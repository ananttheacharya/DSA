impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut map_st = [None; 256];
        let mut map_ts = [None; 256];

        for (a, b) in s.bytes().zip(t.bytes()) {
            let a = a as usize;
            let b = b as usize;

            // s character already maps to something else
            if let Some(mapped) = map_st[a] {
                if mapped != b {
                    return false;
                }
            }

            // t character already maps from something else
            if let Some(mapped) = map_ts[b] {
                if mapped != a {
                    return false;
                }
            }

            map_st[a] = Some(b);
            map_ts[b] = Some(a);
        }

        true
    }
}