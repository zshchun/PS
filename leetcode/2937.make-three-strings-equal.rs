impl Solution {
    pub fn find_minimum_operations(s1: String, s2: String, s3: String) -> i32 {
        let sz: usize = s1.len().min(s2.len()).min(s3.len());
        let mut idx = 0;
        for i in 0..sz {
            let a = s1.chars().nth(i).unwrap();
            let b = s2.chars().nth(i).unwrap();
            let c = s3.chars().nth(i).unwrap();
            if a != b || a != c {
                break;
            }
            idx = i + 1;
        }
        if idx == 0 {
            -1
        } else {
            (s1.len() + s2.len() + s3.len() - (idx * 3)) as i32
        }
    }
}
