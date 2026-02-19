"""
Python module to generate test data for Gauss Elimination
"""

import random


def generate_input_data(n: int = 2, m: int = 2, x: int = 10) -> list[list[int]]:
    """
    Generate n arrays of size m + 1 of integers between 0 and x
    :return: a nested list of integers between 0 and x
    """
    data = []
    for _ in range(n):
        subdata = []
        for _ in range(m + 1):
            subdata.append(random.randint(-1 * x, x))
        data.append(subdata)
    return data


def write_data_to_file(data: list[list[int]], filepath: str = "./data/input.txt") -> None:
    """
    Write data to file

    :param data: a nested list of integers
    :param filepath: a path to a file
    :return: None
    """
    with open(filepath, "w") as f:
        for row in data:
            line = ','.join(map(str, row))
            f.write(line + "\n")


if __name__ == "__main__":
    N = 3000
    print(f"Generating {N}x{N} input data...")
    test_data = generate_input_data(N, N, 100)
    print("Writing to file...")
    write_data_to_file(test_data)
    print("Test data ready!")
