func isIsomorphic(s string, t string) bool {
    mapS_T, mapT_S := make(map[byte]byte), make(map[byte]byte)
    
    for i:=0; i < len(s); i++ {
        if (mapS_T[s[i]] != 0 && mapS_T[s[i]] != t[i] || mapT_S[t[i]] != 0 && mapT_S[t[i]] != s[i]) {
            return false
        } else {
            mapS_T[s[i]] = t[i]
            mapT_S[t[i]] = s[i]
        }
    }
    
    return true
}