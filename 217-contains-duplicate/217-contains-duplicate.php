class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function containsDuplicate($nums) {
        $nums_unique = array_unique($nums);
        if(count($nums) == count($nums_unique)){
            return false;
        }
        else{
            return true;
        }
    }
}