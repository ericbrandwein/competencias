import sys
sys.setrecursionlimit(5010*5010)


longitud = int(input())
cadena = input()

# [indice reves][indice derecho]
dp = [[-1 for i in range(longitud + 2)] for j in range(longitud + 2)]

def levenshtein(indice_reves, indice_derecho):
    if dp[indice_reves][indice_derecho] == -1:
        if indice_reves == -1:
            dp[indice_reves][indice_derecho] = longitud - indice_derecho
        elif indice_derecho == longitud:
            dp[indice_reves][indice_derecho] = indice_reves + 1
        elif cadena[indice_reves] == cadena[indice_derecho]:
            dp[indice_reves][indice_derecho] = levenshtein(indice_reves - 1, indice_derecho + 1)
        else:
            dp[indice_reves][indice_derecho] = 1 + min(
                levenshtein(indice_reves - 1, indice_derecho),
                levenshtein(indice_reves, indice_derecho + 1)
            )
    return dp[indice_reves][indice_derecho]

def solve():
    res = 20000
    for i in range(longitud):
        res = min(res, levenshtein(i-1, i+1), levenshtein(i-1, i), levenshtein(i, i+1))
    print(res)

solve()