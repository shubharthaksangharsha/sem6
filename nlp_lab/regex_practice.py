import re
text_to_search = '''
abcdefghijklmnopqurtuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
1234567890
Ha HaHa
MetaCharacters (Need to be escaped):
. ^ $ * + ? { } [ ] \ | ( )
coreyms.com
321-555-4321
123.555.1234
123*555*1234
800-555-1234
900-555-1234
Mr. Schafer
Mr Smith
Ms Davis
Mrs. Robinson
Mr. T

cat
mat
pat
bat
'''
sentence = 'Start a sentence and then bring it to an end'
# def m(t):
#     #pattern = re.compile(r'^a') #Search for a word at starting position
#     #pattern = re.compile(r'end$') #Search for a word at the end position
#     #pattern = re.compile(r'\d\d\d') #Matches any 3 digit 
#     pattern = re.compile(r'\d\d\d.\d\d\d.\d\d\d\d')
#      pattern = re.compile(r'[89]00[-.]\d\d\d[-.]\d\d\d\d') #only print 800 or 900 
#     matches = pattern.finditer(t)
#     for match in matches:
#         print(match)
#Character set can only choose one value from the set 

pattern = re.compile(r'[a-zA-Z]') #specify a range if '-' places between two characters 
pattern = re.compile(r'[^a-zA-Z]') #if ^ is placed in a character set at starting, it will negogiate opposite (i.e act as a 'not') 
pattern = re.compile(r'\d{3}.\d{3}.\d{4}') #{} quantifier allows to describe range or any specific number 
# pattern = re.compile(r'Mr\.?\s[A-Z]*')
# pattern = re.compile(r'(Mr|Ms|Mrs)\.?\s[A-Z]\w*')
# pattern = re.compile(r'[a-zA-Z.0-9-]+@[a-zA-Z-]+\.(com|edu|net)') #check for emails 
# pattern = re.compile(r'[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+')
# pattern = re.compile(r'https?://(www\.)?(\w+)(\.\w+)') #search for urls 

pattern = re.compile(r'start', re.IGNORECASE) #ignores uppercase/lowercase
pattern = re.compile(r'start', re.I) #same as above (alias) 
#pattern.findall(create a list of match words return empty list if not found)
#pattern.finditer(create a regex object with functionality of telling the match word as well as the index of the match word)
#pattern.search (search for word at any position return None if not found)
#pattern.match (search for the word at the begining position only return None if not found)

matches = pattern.match(sentence)
print(matches)
# for match in matches:
    # print(match)

# with open('/home/shubharthak/Desktop/sem6/nlp_lab/urls.txt', 'r') as f:
    # contents = f.read()
    # subbed_urls = pattern.sub(r'\2\3', contents)
    # print(subbed_urls)
    # matches = pattern.findall(contents)
    # matches = pattern.finditer(contents)
    # for match in matches:
        # print(match.group(3)) #call group index 

