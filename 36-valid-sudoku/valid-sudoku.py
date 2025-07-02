class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        r_map: Defaultdict[int,Set[str]] = defaultdict(set)
        c_map: Defaultdict[int,Set[str]] = defaultdict(set)
        rc_map: Defaultdict[Tuple[int,int],Set[str]]  = defaultdict(set)

        for i in range(9):
            for j in range(9):
                elem = board[i][j]
                if elem=='.': continue
                else:
                    if elem in r_map[i]: return False
                    if elem in c_map[j]: return False
                    r = i//3
                    c = j//3
                    if elem in rc_map[(r,c)]: return False
                    r_map[i].add(elem)
                    c_map[j].add(elem)
                    rc_map[(r,c)].add(elem)
        
        return True

        