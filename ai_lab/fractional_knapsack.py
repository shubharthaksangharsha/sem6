#By Shubharthak, 20BCS6872
from typing import List

def get_fractional_knapsack(profits: List[int], weights: List[int], capacity: int) -> tuple():
    '''
    Returns the Maximum Profit and its fraction values(descending order) 
    Args:
        profits: List of profits of int value: List[int]
        weights: List of weights associciated of each profits: List[int]
        capacity: Maximum Capacity of Bag: int
    Returns: 
        Tuple of Maximum Profit with its fraction value: Tuple(int, List[int])
    '''
    index = list(range(len(profits)))
    ratio = [v/w for v, w in zip(profits, weights)]
    index.sort(key=lambda i: ratio[i], reverse=True)
    max_value = 0 
    fractions = []
    for i in index: 
        print(f"Bag {i+1}, Profit: {profits[i]}, Weight: {weights[i]}, Weight Left: {capacity}, Maximum Profit: {max_value}")
        if weights[i] <= capacity:
            fractions.append(1)
            max_value += profits[i]
            capacity -= weights[i]
            print(f"Bag {i+1}, Profit: {profits[i]}, Weight: {weights[i]}, Weight Left: {capacity}, Maximum Profit: {max_value}")
        else:
            fractions.append(capacity/ weights[i])
            max_value+= profits[i] * capacity / weights[i]
            print(f"Bag {i+1}, Profit: {profits[i]}, Weight: {weights[i]}, Weight Left: {capacity}, Maximum Profit: {max_value}")
            break
    return max_value, fractions

if __name__ == '__main__':
    capacity = int(input('Enter Capacity of Bag: '))
    n = int(input('Enter total number of items: '))
    profit = input(f'Enter the values of the {n} item(s) in order seperated by space: ').split()
    profits = [int(v) for v in profit]
    weights = input(f'Enter the weights of the {n} item(s) in order seperated by space: ').split()
    weights = [int(v) for v in weights]
    maxvalue, fraction = get_fractional_knapsack(profits, weights, capacity)
    print(f"Maximum Profit: {maxvalue}")
    print(f"Fractions in which items should be taken: {fraction}")