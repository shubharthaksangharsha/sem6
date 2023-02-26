'''
    CC: coordinating conjunction
    CD: cardinal digit
    DT: determiner
    EX: existential there
    FW: foreign word
    IN: preposition/subordinating conjunction
    JJ: adjective
    JJR: adjective, comparative
    JJS: adjective, superlative
    LS: list marker
    MD: modal
    NN: noun, singular or mass
    NNS: noun, plural
    NNP: proper noun, singular
    NNPS: proper noun, plural
    PDT: predeterminer
    POS: possessive ending
    PRP: personal pronoun
    PRP$: possessive pronoun
    RB: adverb
    RBR: adverb, comparative
    RBS: adverb, superlative
    RP: particle
    SYM: symbol
    TO: to
    UH: interjection
    VB: verb, base form
    VBD: verb, past tense
    VBG: verb, gerund/present participle
    VBN: verb, past participle
    VBP: verb, non-3rd person singular present
    VBZ: verb, 3rd person singular present
    WDT: wh-determiner
    WP: wh-pronoun
    WP$: possessive wh-pronoun
    WRB: wh-adverb
'''
import nltk
from nltk.tokenize import word_tokenize

# Download necessary NLTK resources
# nltk.download('averaged_perceptron_tagger')

# Input text
text = input("Enter a string: ")

# Tokenize the text into words
words = word_tokenize(text)

# Perform POS tagging
pos_tags = nltk.pos_tag(words)

# Print the tagged text
print(pos_tags)
