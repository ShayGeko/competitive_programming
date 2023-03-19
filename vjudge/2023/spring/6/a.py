def check_palindrome(input_string):
    input_string = input_string.lower().replace(" ", "").replace(",", "").replace("!", "").replace(".", "").replace(":", "")
    length = len(input_string)
    start = 0
    end = length - 1
    remove_count = 0
    while start < end:
        if input_string[start] != input_string[end]:
            remove_count += 1
        start += 1
        end -= 1
    return remove_count

a = input()
b = check_palindrome(a)

print(b)