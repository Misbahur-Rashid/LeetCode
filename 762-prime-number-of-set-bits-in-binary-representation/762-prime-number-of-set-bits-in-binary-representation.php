class Solution {
    function isPrime($number){
        if($number == 1){
            return false;
        }
        for($h=2; $h<$number; $h++){
            if(($number % $h) == 0){
                return false;
            }
          
        }
          return true;
    }
    function countPrimeSetBits($left, $right) {
        $count = 0;
        for($h=$left; $h<=$right; $h++){
            $bin = decbin($h);
            $setBits = str_replace("0", "", "$bin");
            $setBitsNumber = strlen($setBits);
            if($this->isPrime($setBitsNumber)){
                $count++;
            }
        }
        return $count;
    }
}