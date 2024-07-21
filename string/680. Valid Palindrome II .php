class Solution {
    function validPalindrome($s) {
        $left = 0;
        $right = strlen($s) - 1;
        while ($left <= $right) {
            if ($s[$left] != $s[$right]) {
                $leftstr = substr_replace($s, "", $left, 1);
                $rightstr = substr_replace($s, "", $right, 1);
                return $leftstr == strrev($leftstr) or $rightstr == strrev($rightstr);
            }
            $left++;
            $right--;
        }
        return true;
    }
}
