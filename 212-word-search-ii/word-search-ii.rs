struct TrieNode {
    children: [Option<Box<TrieNode>>; 26],
    word_index: Option<usize>,
}

impl TrieNode {
    fn new() -> Self {
        Self {
            children: std::array::from_fn(|_| None),
            word_index: None,
        }
    }

    fn insert(&mut self, word: &str, index: usize) {
        let mut curr = self;

        for b in word.bytes() {
            let c = (b - b'a') as usize;

            curr = curr.children[c]
                .get_or_insert_with(|| Box::new(TrieNode::new()));
        }

        curr.word_index = Some(index);
    }
}

impl Solution {
    pub fn find_words(
        mut board: Vec<Vec<char>>,
        words: Vec<String>,
    ) -> Vec<String> {
        let mut root = TrieNode::new();

        // Build Trie
        for (i, word) in words.iter().enumerate() {
            root.insert(word, i);
        }

        let m = board.len();
        let n = board[0].len();

        let mut result = Vec::new();

        for r in 0..m {
            for c in 0..n {
                Self::dfs(
                    &mut board,
                    r,
                    c,
                    &mut root,
                    &words,
                    &mut result,
                );
            }
        }

        result
    }

    fn dfs(
        board: &mut Vec<Vec<char>>,
        r: usize,
        c: usize,
        node: &mut TrieNode,
        words: &Vec<String>,
        result: &mut Vec<String>,
    ) {
        let ch = board[r][c];

        if ch == '#' {
            return;
        }

        let index = (ch as u8 - b'a') as usize;

        let next = match node.children[index].as_mut() {
            Some(next) => next,
            None => return,
        };

        // Found a complete word
        if let Some(word_index) = next.word_index {
            result.push(words[word_index].clone());

            // Prevent duplicates
            next.word_index = None;
        }

        // Mark as visited
        board[r][c] = '#';

        // Up
        if r > 0 {
            Self::dfs(
                board,
                r - 1,
                c,
                next,
                words,
                result,
            );
        }

        // Down
        if r + 1 < board.len() {
            Self::dfs(
                board,
                r + 1,
                c,
                next,
                words,
                result,
            );
        }

        // Left
        if c > 0 {
            Self::dfs(
                board,
                r,
                c - 1,
                next,
                words,
                result,
            );
        }

        // Right
        if c + 1 < board[0].len() {
            Self::dfs(
                board,
                r,
                c + 1,
                next,
                words,
                result,
            );
        }

        // Restore cell
        board[r][c] = ch;
    }
}