public class pruebas {
    public static void main(String[] args) {
        int[] nums = {1,1,0,1,1,1};
        int[] ans = new int[10];
        int max = 0;
        int current = 0;

        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 1){
                current++;
                continue;
            }

            if(max < current){
                max = current;
                current = 0;
            }  
        }

        if(max < current){
            max = current;
            current = 0;
        } 
        
        System.out.println(max);
        
        
    }
}
