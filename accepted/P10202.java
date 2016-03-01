import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class P10202 {
	List<Integer> S, A;
	
	public boolean solve(){
		boolean finished, b;
		boolean visited[];

			for(int i=2; i<S.size(); i++){
			   
			   if((S.get(0) + S.get(1) - S.get(i)) % 2 != 0)
			      continue;
			      
			   finished = true;   
			   visited  = new boolean[50];
               A = new ArrayList<Integer>();
			   A.add((S.get(0) + S.get(1) - S.get(i))/2);
			   b = true;
			   for(int j=0; j<S.size(); j++){
			       if(visited[j])
			          continue;
			       A.add(S.get(j) - A.get(0));
			       for(int k=0; k<(A.size()-1); k++){
			          b = true;
			          for(int l=0; l<S.size(); l++){
			              if(A.get(k) + A.get(A.size()-1) == S.get(l) && visited[l] == false){
			                visited[l] = true;
			                b = false;
			                break;
			              }
			           }
			           if(b){
			              finished = false;
			              break;
			           }
			       }
			       if(b){ // nao contem numero
			          finished = false;
			          break;
			       }
			   }
			   if(finished)
			      return true;   
			}
			return false;
		}
	public void execute() {
		int n, m;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt()) {
			 n = sc.nextInt();					
		     m = (n*(n-1))/2;
		     S = new ArrayList<Integer>();
		     for(int i=0; i<m; i++)
		    	 S.add(sc.nextInt());
		     
		     Collections.sort(S);
		        
		     
		     if(solve()){
		       
		       for(int i=0; i<n; i++)
		           if(i > 0)
		             System.out.printf(" %d",A.get(i));
		           else
		             System.out.printf("%d",A.get(0));  
		       System.out.printf("\n");
		     } else
		        System.out.printf("Impossible\n");

		} 
	}
	public static void main(String[] args) {
		new P10202().execute();
	}

}
