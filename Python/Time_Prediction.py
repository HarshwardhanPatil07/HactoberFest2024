import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

# Generate synthetic time series data
np.random.seed(42)
time = np.arange(100)
data = 0.5 * time + 10 + np.random.normal(size=time.size)

# Prepare data for linear regression
X = time.reshape(-1, 1)  # Reshape for sklearn
y = data

# Split into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create and train the model
model = LinearRegression()
model.fit(X_train, y_train)

# Make predictions
future_time = np.arange(100, 120).reshape(-1, 1)
predictions = model.predict(future_time)

# Plot the results
plt.figure(figsize=(10, 6))
plt.scatter(X, y, color='blue', label='Historical Data')
plt.plot(X, model.predict(X), color='orange', label='Regression Line')
plt.scatter(future_time, predictions, color='red', label='Future Predictions')
plt.title('Time Series Prediction')
plt.xlabel('Time')
plt.ylabel('Value')
plt.legend()
plt.show()
