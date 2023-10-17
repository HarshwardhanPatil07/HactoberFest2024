const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Enter width of diamond: ", function (input) {
  const diamondWidth = parseInt(input);

  // Check input constraints
  if (diamondWidth < 1 || diamondWidth > 200) {
    console.log("Invalid input. Please enter a value between 1 and 200.");
    rl.close();
    return;
  }

  // Function to generate spaces
  const generateSpaces = (count) => " ".repeat(count);

  // Function to generate hash symbols
  const generateHashes = (count) => "# ".repeat(count);

  // Print upper half of diamond
  for (let i = 0; i < diamondWidth; i++) {
    const spacesCount = diamondWidth - i - 1;
    const hashesCount = i + 1;
    console.log(generateSpaces(spacesCount) + generateHashes(hashesCount));
  }

  // Print lower half of diamond
  for (let i = diamondWidth - 2; i >= 0; i--) {
    const spacesCount = diamondWidth - i - 1;
    const hashesCount = i + 1;
    console.log(generateSpaces(spacesCount) + generateHashes(hashesCount));
  }

  rl.close();
});


/*
Sample output for width 3:

      # 
     # # 
    # # # 
     # # 
      # 
      
*/