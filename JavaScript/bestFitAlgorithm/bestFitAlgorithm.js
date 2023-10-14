const Decimal = require('decimal.js');

// Constants
const RotationType = {
  RT_WHD: 0,
  RT_HWD: 1,
  RT_HDW: 2,
  RT_DHW: 3,
  RT_DWH: 4,
  RT_WDH: 5,
  ALL: [0, 1, 2, 3, 4, 5],
};

const Axis = {
  WIDTH: 0,
  HEIGHT: 1,
  DEPTH: 2,
  ALL: [0, 1, 2],
};

// Helper functions
function rectIntersect(item1, item2, x, y) {
  const d1 = item1.getDimension();
  const d2 = item2.getDimension();

  const cx1 = item1.position[x] + d1[x] / 2;
  const cy1 = item1.position[y] + d1[y] / 2;
  const cx2 = item2.position[x] + d2[x] / 2;
  const cy2 = item2.position[y] + d2[y] / 2;

  const ix = Math.max(cx1, cx2) - Math.min(cx1, cx2);
  const iy = Math.max(cy1, cy2) - Math.min(cy1, cy2);

  return ix < (d1[x] + d2[x]) / 2 && iy < (d1[y] + d2[y]) / 2;
}

function intersect(item1, item2) {
  return (
    rectIntersect(item1, item2, Axis.WIDTH, Axis.HEIGHT) &&
    rectIntersect(item1, item2, Axis.HEIGHT, Axis.DEPTH) &&
    rectIntersect(item1, item2, Axis.WIDTH, Axis.DEPTH)
  );
}

function getLimitNumberOfDecimals(numberOfDecimals) {
  return new Decimal('1.' + '0'.repeat(numberOfDecimals));
}

function setToDecimal(value, numberOfDecimals) {
  const limit = getLimitNumberOfDecimals(numberOfDecimals);
  return new Decimal(value).toDecimalPlaces(numberOfDecimals);
}


// Item class
class Item {
  constructor(name, width, height, depth, weight) {
    this.name = name;
    this.width = width;
    this.height = height;
    this.depth = depth;
    this.weight = weight;
    this.rotationType = 0;
    this.position = START_POSITION;
    this.numberOfDecimals = DEFAULT_NUMBER_OF_DECIMALS;
  }

  formatNumbers(numberOfDecimals) {
    this.width = setToDecimal(this.width, numberOfDecimals);
    this.height = setToDecimal(this.height, numberOfDecimals);
    this.depth = setToDecimal(this.depth, numberOfDecimals);
    this.weight = setToDecimal(this.weight, numberOfDecimals);
    this.numberOfDecimals = numberOfDecimals;
  }

  string() {
    return `${this.name}(${this.width}x${this.height}x${this.depth}, weight: ${this.weight}) pos(${this.position}) rt(${this.rotationType}) vol(${this.getVolume()})`;
  }

  getVolume() {
    return setToDecimal(this.width * this.height * this.depth, this.numberOfDecimals);
  }

  getDimension() {
    let dimension = [];
    switch (this.rotationType) {
      case RotationType.RT_WHD:
        dimension = [this.width, this.height, this.depth];
        break;
      case RotationType.RT_HWD:
        dimension = [this.height, this.width, this.depth];
        break;
      case RotationType.RT_HDW:
        dimension = [this.height, this.depth, this.width];
        break;
      case RotationType.RT_DHW:
        dimension = [this.depth, this.height, this.width];
        break;
      case RotationType.RT_DWH:
        dimension = [this.depth, this.width, this.height];
        break;
      case RotationType.RT_WDH:
        dimension = [this.width, this.depth, this.height];
        break;
    }
    return dimension;
  }
}

// Bin class
class Bin {
  constructor(name, width, height, depth, maxWeight) {
    this.name = name;
    this.width = width;
    this.height = height;
    this.depth = depth;
    this.maxWeight = maxWeight;
    this.items = [];
    this.unfittedItems = [];
    this.numberOfDecimals = DEFAULT_NUMBER_OF_DECIMALS;
  }

  formatNumbers(numberOfDecimals) {
    this.width = setToDecimal(this.width, numberOfDecimals);
    this.height = setToDecimal(this.height, numberOfDecimals);
    this.depth = setToDecimal(this.depth, numberOfDecimals);
    this.maxWeight = setToDecimal(this.maxWeight, numberOfDecimals);
    this.numberOfDecimals = numberOfDecimals;
  }

  string() {
    return `${this.name}(${this.width}x${this.height}x${this.depth}, max_weight:${this.maxWeight}) vol(${this.getVolume()})`;
  }

  getVolume() {
    return setToDecimal(this.width * this.height * this.depth, this.numberOfDecimals);
  }

  getTotalWeight() {
    let totalWeight = 0;
    for (const item of this.items) {
      totalWeight += item.weight;
    }
    return setToDecimal(totalWeight, this.numberOfDecimals);
  }

  putItem(item, pivot) {
    let fit = false;
    const validItemPosition = item.position;
    item.position = pivot;

    for (let i = 0; i < RotationType.ALL.length; i++) {
      item.rotationType = RotationType.ALL[i];
      const dimension = item.getDimension();
      if (
        this.width < pivot[0] + dimension[0] ||
        this.height < pivot[1] + dimension[1] ||
        this.depth < pivot[2] + dimension[2]
      ) {
        continue;
      }

      fit = true;

      for (const currentItemInBin of this.items) {
        if (intersect(currentItemInBin, item)) {
          fit = false;
          break;
        }
      }

      if (fit) {
        if (this.getTotalWeight() + item.weight > this.maxWeight) {
          fit = false;
          return fit;
        }
        this.items.push(item);
      }

      if (!fit) {
        item.position = validItemPosition;
      }
      return fit;
    }

    if (!fit) {
      item.position = validItemPosition;
    }
    return fit;
  }
}

// Packer class
class Packer {
  constructor() {
    this.bins = [];
    this.items = [];
    this.unfitItems = [];
    this.totalItems = 0;
  }

  addBin(bin) {
    this.bins.push(bin);
  }

  addItem(item) {
    this.totalItems = this.items.length + 1;
    this.items.push(item);
  }

  packToBin(bin, item) {
    let fitted = false;

    if (bin.items.length === 0) {
      const response = bin.putItem(item, START_POSITION);
      if (!response) {
        bin.unfittedItems.push(item);
      }
      return;
    }

    for (let axis = 0; axis < 3; axis++) {
      const itemsInBin = bin.items;
      for (const ib of itemsInBin) {
        let pivot = [0, 0, 0];
        const [w, h, d] = ib.getDimension();
        if (axis === Axis.WIDTH) {
          pivot = [ib.position[0] + w, ib.position[1], ib.position[2]];
        } else if (axis === Axis.HEIGHT) {
          pivot = [ib.position[0], ib.position[1] + h, ib.position[2]];
        } else if (axis === Axis.DEPTH) {
          pivot = [ib.position[0], ib.position[1], ib.position[2] + d];
        }

        if (bin.putItem(item, pivot)) {
          fitted = true;
          break;
        }
      }
      if (fitted) {
        break;
      }
    }

    if (!fitted) {
      bin.unfittedItems.push(item);
    }
  }

  pack(biggerFirst = false, distributeItems = false, numberOfDecimals = DEFAULT_NUMBER_OF_DECIMALS) {
    for (const bin of this.bins) {
      bin.formatNumbers(numberOfDecimals);
    }

    for (const item of this.items) {
      item.formatNumbers(numberOfDecimals);
    }

    this.bins.sort((a, b) => {
      return b.getVolume() - a.getVolume();
    });

    this.items.sort((a, b) => {
      return b.getVolume() - a.getVolume();
    });

    for (const bin of this.bins) {
      for (const item of this.items) {
        this.packToBin(bin, item);
      }

      if (distributeItems) {
        for (const item of bin.items) {
          this.items.splice(this.items.indexOf(item), 1);
        }
      }
    }
  }
}

// Constants
const DEFAULT_NUMBER_OF_DECIMALS = 3;
const START_POSITION = [0, 0, 0];


// Function to find a box that can accommodate all items at once
function findBoxForAllItems(items, bins) {
  for (const bin of bins) {
    let canFitAllItems = true;

    // Check if all items can fit in the current box
    for (const item of items) {
      let itemFits = false;

      // Try all possible rotations of the item
      for (let i = 0; i < RotationType.ALL.length; i++) {
        const originalRotationType = item.rotationType;
        item.rotationType = RotationType.ALL[i];
        const dimension = item.getDimension();

        console.log(dimension)

        if (
          bin.width >= dimension[0] &&
          bin.height >= dimension[1] &&
          bin.depth >= dimension[2]
        ) {
          // Check if the item can fit in the box without overlapping other items
          let itemFitsInBox = true;
          for (const existingItem of bin.items) {
            if (intersect(existingItem, item)) {
              itemFitsInBox = false;
              break;
            }
          }

          if (itemFitsInBox) {
            itemFits = true;
            break; // The item fits in this rotation, move to the next item
          }
        }
        item.rotationType = originalRotationType;
      }

      if (!itemFits) {
        canFitAllItems = false;
        break; // The current box cannot accommodate all items
      }
    }

    if (canFitAllItems) {
      return bin; // Return the first box that can fit all items
    }
  }

  return null; // No box can fit all items
}

// Example usage:
const items = [
  new Item('Item1', 8, 5, 2, 3),
  new Item('Item2', 15, 10, 2, 5),
  new Item('Item3', 3, 2, 1, 1),
  new Item('Item4', 7, 6, 2, 4),
];

const bins = [
  new Bin("Small Box", 30, 30, 30, 1000),
  new Bin("Medium Box", 40, 40, 40, 2000),
  new Bin("Large Box", 50, 50, 50, 5000),
  new Bin("Extra-Large Box", 60, 60, 60, 10000),
  new Bin("Book Box", 30, 20, 20, 1300),
  new Bin("Wardrobe Box", 60, 50, 120, 4000),
  new Bin("Dish-Pack Box", 60, 40, 30, 2000),
  new Bin("File Box", 40, 30, 30, 1000),
]
const selectedBox = findBoxForAllItems(items, bins);

console.log(selectedBox)

if (selectedBox) {
  console.log(`Items can fit in ${selectedBox.name}`);
} else {
  console.log("No box can fit all items.");
}
