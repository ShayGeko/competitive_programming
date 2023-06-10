def count_numbers_less_than_with_mask_formula(x, mask):
    num_bits_mask = bin(mask).count('1')  # Number of set bits in the mask
    complement_mask = (1 << x.bit_length()) - 1 - mask

    count = 2 ** num_bits_mask - count_numbers_less_than_with_mask_formula(x - 1, complement_mask)
    return count if x > 0 else 0

[a, b] = map((lambda x: int(x)),input().split())
print(a, b)
print (count_numbers_less_than_with_mask_formula(a, b))

