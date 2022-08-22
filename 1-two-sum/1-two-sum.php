class Solution {

    function twoSum($nums, $target) {
        $sum = 0;
        $number1 = 0;
        $number2 = 0;
        for($i=0; $i<count($nums); $i++){
            $number1 = $nums[$i];
            for($j=0; $j<count($nums); $j++){
                if($i == $j){
                    continue;
                }
                $number2 = $nums[$j];
                if(($number1 + $number2) == $target){
                    break 2;
                }
            }
        }
        return[$i, $j];
    }
}