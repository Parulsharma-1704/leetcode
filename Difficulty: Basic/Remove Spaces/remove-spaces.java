class Solution {
    public String removeSpaces(String s) {
        // code here
        StringBuilder sb=new StringBuilder();
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s.charAt(i)==' '){
                continue;
            }
            sb.append(s.charAt(i));
        }
        String ans=sb.toString();
        return ans;
    }
}