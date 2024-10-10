# github username : Gulshan-Laskar, date : 10/10/2024

# Goal: Contribute to open source during Hacktoberfest by adding a matrix exponential raise function

# Description: 
# As a newcomer to open source development, I am excited to participate in Hacktoberfest and contribute to the community. After exploring various topics, I believe that implementing a matrix exponential raise function would be an interesting addition to this repository. This function can be useful for future users who need to raise a matrix to a given power using matrix exponentiation. By adding this functionality, I hope to contribute to the growth and usefulness of this repository.



import numpy as np

def matrix_exponentiation(matrix, power):
    """
    Raises a matrix to a given power using matrix exponentiation.

    Args:
        matrix (numpy.ndarray): The input matrix.
        power (int): The power to raise the matrix to.

    Returns:
        numpy.ndarray: The resulting matrix after raising it to the given power.
    """
    if power == 0:
        return np.eye(matrix.shape[0])  # Identity matrix of the same size as the input matrix

    result = np.copy(matrix)
    for _ in range(power - 1):
        result = np.dot(result, matrix)

    return result

matrix = np.array([[1, 2], [3, 4]])

# Raise the matrix to the power of 2
power = 2
result = matrix_exponentiation(matrix, power)
print(result)