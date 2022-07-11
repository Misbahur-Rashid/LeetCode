class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function sortedSquares($nums) {
        foreach($nums as $key => $value){
            $nums[$key] = pow($value, 2);
        }
        sort($nums);
        return $nums;
    }
}