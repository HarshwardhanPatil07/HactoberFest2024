import numpy as np

class RidgeRegression:
    def __init__(self, alpha=1.0):
        self.alpha = alpha  # Regularization parameter (λ)

    def fit(self, X, y):
        # Add a column of ones for the bias term
        X = np.column_stack((np.ones(len(X)), X))
        
        # Identity matrix with 0 in the first element for bias term
        I = np.identity(X.shape[1])
        I[0, 0] = 0
        
        # Closed-form solution for ridge regression
        self.theta = np.linalg.inv(X.T @ X + self.alpha * I) @ X.T @ y

    def predict(self, X):
        # Add a column of ones for the bias term
        X = np.column_stack((np.ones(len(X)), X))
        
        # Make predictions
        return X @ self.theta

# Example usage:
if __name__ == "__main__":
    # Generate some sample data
    np.random.seed(0)
    X = 2 * np.random.rand(100, 3)
    y = 4 + X[:, 0] + 3 * X[:, 1] + 2 * X[:, 2] + np.random.randn(100)

    # Create and fit the Ridge Regression model
    ridge_reg = RidgeRegression(alpha=1.0)
    ridge_reg.fit(X, y)

    # Make predictions
    y_pred = ridge_reg.predict(X)

    # Print the coefficients and intercept
    print("Coefficients:", ridge_reg.theta[1:])
    print("Intercept:", ridge_reg.theta[0])
