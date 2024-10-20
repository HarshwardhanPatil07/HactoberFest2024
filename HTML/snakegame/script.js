// Game settings
const canvas = document.getElementById("gameCanvas");
const ctx = canvas.getContext("2d");
const boxSize = 20;
const canvasSize = 400;
canvas.width = canvasSize;
canvas.height = canvasSize;

// Initial snake position and direction
let snake = [{ x: 200, y: 200 }];
let direction = { x: 0, y: 0 };
let food = generateFood();
let score = 0;

// Get game over elements
const gameOverScreen = document.getElementById("gameOverScreen");
const finalScore = document.getElementById("finalScore");
const nameInput = document.getElementById("nameInput");
const submitScoreButton = document.getElementById("submitScoreButton");
const historyTableBody = document.querySelector("#historyTable tbody");

// Event listener for keyboard input
document.addEventListener("keydown", changeDirection);
submitScoreButton.addEventListener("click", submitScore);

// Function to generate random food position
function generateFood() {
    return {
        x: Math.floor(Math.random() * (canvasSize / boxSize)) * boxSize,
        y: Math.floor(Math.random() * (canvasSize / boxSize)) * boxSize,
    };
}

// Main game loop
function gameLoop() {
    if (isGameOver()) {
        endGame();
        return;
    }

    clearCanvas();
    moveSnake();
    drawFood();
    drawSnake();
    updateScore();
}

// Move the snake
function moveSnake() {
    const head = {
        x: snake[0].x + direction.x * boxSize,
        y: snake[0].y + direction.y * boxSize,
    };

    // Check if the snake eats food
    if (head.x === food.x && head.y === food.y) {
        score++;
        food = generateFood();
    } else {
        snake.pop(); // Remove the last part if no food is eaten
    }

    snake.unshift(head); // Add new head to the snake
}

// Draw the snake
function drawSnake() {
    ctx.fillStyle = "lime";
    snake.forEach((part) => {
        ctx.fillRect(part.x, part.y, boxSize, boxSize);
    });
}

// Draw the food
function drawFood() {
    ctx.fillStyle = "red";
    ctx.fillRect(food.x, food.y, boxSize, boxSize);
}

// Clear the canvas
function clearCanvas() {
    ctx.clearRect(0, 0, canvasSize, canvasSize);
}

// Change direction based on keyboard input
function changeDirection(event) {
    const key = event.keyCode;
    if (key === 37 && direction.x === 0) {
        direction = { x: -1, y: 0 }; // Left
    } else if (key === 38 && direction.y === 0) {
        direction = { x: 0, y: -1 }; // Up
    } else if (key === 39 && direction.x === 0) {
        direction = { x: 1, y: 0 }; // Right
    } else if (key === 40 && direction.y === 0) {
        direction = { x: 0, y: 1 }; // Down
    }
}

// Check if the game is over
function isGameOver() {
    const head = snake[0];

    // Check if the snake hits the walls
    if (head.x < 0 || head.x >= canvasSize || head.y < 0 || head.y >= canvasSize) {
        return true;
    }

    // Check if the snake hits itself
    for (let i = 1; i < snake.length; i++) {
        if (head.x === snake[i].x && head.y === snake[i].y) {
            return true;
        }
    }

    return false;
}

// Update the score display
function updateScore() {
    document.getElementById("score").innerText = score;
}

// End the game and show the game over screen
function endGame() {
    gameOverScreen.style.display = "block";
    finalScore.innerText = score;
    clearInterval(gameInterval); // Stop the game loop
}

// Submit the score and name
function submitScore() {
    const name = nameInput.value.trim();
    if (name === "") {
        alert("Please enter your name.");
        return;
    }

    // Add the score to the history table
    const row = document.createElement("tr");
    row.innerHTML = `<td>${name}</td><td>${score}</td>`;
    historyTableBody.appendChild(row);

    // Reset the game
    resetGame();
}

// Reset the game
function resetGame() {
    snake = [{ x: 200, y: 200 }];
    direction = { x: 0, y: 0 };
    food = generateFood();
    score = 0;
    document.getElementById("score").innerText = score;
    nameInput.value = ""; // Clear the input field
    gameOverScreen.style.display = "none"; // Hide the game over screen
    gameInterval = setInterval(gameLoop, 100); // Restart the game loop
}

// Start the game loop
let gameInterval = setInterval(gameLoop, 100);
    