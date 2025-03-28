# Define a simple grammar in CNF (Chomsky Normal Form)
grammar = {
    "S": [["NP", "VP"]],
    "NP": [["Det", "Noun"]],
    "VP": [["Verb", "NP"]],
    "Det": ["a", "the"],
    "Noun": ["cat", "dog"],
    "Verb": ["chased", "saw"]
}

def cyk_parser(grammar, sentence):
    n = len(sentence)
    # Initialize the parse table with empty sets
    table = [[set() for _ in range(n)] for _ in range(n)]

    # Fill the diagonal of the table with terminal symbols
    for i in range(n):
        word = sentence[i]
        for lhs, rhs_list in grammar.items():
            for rhs in rhs_list:
                if word in rhs:
                    table[i][i].add(lhs)

    # Fill the table for substrings of length > 1
    for span in range(2, n + 1):  # span is the length of the substring
        for start in range(n - span + 1):
            end = start + span - 1
            for mid in range(start, end):
                for lhs, rhs_list in grammar.items():
                    for rhs in rhs_list:
                        if len(rhs) == 2:  # Only handle binary rules (e.g., A -> B C)
                            if rhs[0] in table[start][mid] and rhs[1] in table[mid + 1][end]:
                                table[start][end].add(lhs)

    # Return the result for the full sentence
    return table[0][n - 1]

# Test the parser with a sample sentence
sentence = ["the", "cat", "chased", "the", "dog"]
#sentence = "the skibidi sigma chased the gyatt".split()
print(sentence)
parse_result = cyk_parser(grammar, sentence)
print(f"Parse result: {parse_result}")
