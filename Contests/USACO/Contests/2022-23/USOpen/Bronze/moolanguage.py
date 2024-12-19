def solve():
    N, C, P = map(int, input().split())
    nouns, tverbs, iverbs, conjs = [], [], [], []
    for _ in range(N):
        word, t = input().split()
        if t[0] == "n":
            nouns.append(word)
        if t[0] == "t":
            tverbs.append(word)
        if t[0] == "i":
            iverbs.append(word)
        if t[0] == "c":
            conjs.append(word)
    ans = (0, 0, 0, 0)
    for n_tverb in range(len(tverbs) + 1):
        n_iverb = min(len(iverbs), len(nouns) - 2 * n_tverb)
        while n_iverb >= 0:
            n_conj = min(len(conjs), (n_tverb + n_iverb) // 2)
            if n_tverb + n_iverb - n_conj <= P:
                break
            n_iverb -= 1
        if n_iverb < 0:
            continue
        extra_nouns = min(C, len(nouns) - (n_iverb + 2 * n_tverb))
        if n_tverb == 0:
            extra_nouns = 0
        n_words = 3 * n_tverb + 2 * n_iverb + n_conj + extra_nouns
        ans = max(ans, (n_words, n_tverb, n_iverb, n_conj))

    n_words, n_tverb, n_iverb, n_conj = ans
    print(n_words)
    basic_sentences = [nouns.pop() + " " + iverbs.pop() for _ in range(n_iverb)] + [
        nouns.pop() + " " + tverbs.pop() + " " + nouns.pop() for _ in range(n_tverb)
    ]
    while n_tverb > 0 and C > 0 and len(nouns) > 0:
        basic_sentences[-1] += ", " + nouns.pop()
        C -= 1
    compound_sentences = [
        basic_sentences.pop() + " " + conjs.pop() + " " + basic_sentences.pop()
        for _ in range(n_conj)
    ]
    sentences = [sentence + "." for sentence in basic_sentences + compound_sentences]
    print(" ".join(sentences))


T = int(input())
for t in range(T):
    solve()