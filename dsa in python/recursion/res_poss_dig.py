def bitStrings(n): 
    if n == 0: return []
    if n == 1: return ["O", "l"]
    return [ digit + bitString for digit in bitStrings(1) for bitString in bitStrings(n- 1)]
    
print(bitStrings(3))