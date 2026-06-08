impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        let (mut x, mut y) = (0, 0);
        for c in moves.chars() {
            match c {
                'D' => y += 1,
                'U' => y -= 1,
                'L' => x -= 1,
                'R' => x += 1,
                _ => (),
            }
        }
        if x == 0 && y == 0 { true } else { false }
    }
}
