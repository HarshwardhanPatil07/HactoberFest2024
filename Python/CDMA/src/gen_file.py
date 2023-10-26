'''File Generator Module'''


PATH = "./textfiles/input/input"

file_no = int(input('Enter Number of Files : '))
msg = input('Enter text : ')

def generate_files(num):
    '''Function for generating files'''
    while num:
        with open(PATH + str(num) + '.txt', 'w', encoding='utf-8') as fptr: fptr.write(msg)
        num -= 1
    print('Done!')


# if len(msg) == 15 or len(msg) == 30 or len(msg) == 50: generate_files(file_no)
if len(msg) in (15, 30, 50): generate_files(file_no)
else:
    consent = input("Not Desired Length. Still Want to Write? (y/N): ")
    # if consent == 'y' or consent == 'Y': generate_files(file_no)
    if consent in ('y', 'Y'): generate_files(file_no)
    else: print('Nothing Written!')


# 50 => THIS IS THE RUNNING HEAD IN UP TO FIFTY CHARACTERS
# 30 => THE IRREGULAR MOVE CANNOT LOSE
# 15 => I'M ATANU GHOSH
