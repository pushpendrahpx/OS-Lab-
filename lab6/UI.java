/*
    Created by Pushpendra Vishwakarma
    Sardar Vallabhbhai National Institute of Technology, Surat

*/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


class Process{
    public int pid;
    public int s;
    public int e;
    public boolean status;
    Process(int pid,int s,int e){
        this.pid = pid;
        this.s = s;
        this.e = e;
        this.status= true;
    }
    
}
class UI {
    private int i= 0;
    private Boolean[] memory;
    private ArrayList<Process> ledger;
    UI(){
        memory = new Boolean[1024];
        Arrays.fill(memory, Boolean.FALSE);
        
        ledger = new ArrayList<Process>();
    }

    public void displayMemory(){
        System.out.println("[");
        for(Boolean i:memory){
            if(i) System.out.print("#"); else System.out.print("_");
        }
        System.out.print("]");
    }
    public boolean checkAllocation(int start, int end){
       
        for(int i = start; i <= end; i++){
            if(memory[i] == true) return false; 
        }
        return true;
    }

    /*
        In this if we want to allocate at some location by giving 2 inputs, start & end
    */
    public boolean allocate(int start, int end){
        if(checkAllocation(start, end)){
            for(int i=start; i <= end; i++){
                memory[i] = true;
            }
            Process p = new Process(i++, start, end);
            ledger.add(p);

            return true;
        }else{
            System.out.println("MEMORY NOT AVAILABLE");
            return false;
        }
    }


    public boolean FirstFitAllocation(int space){
        int c =0;
        int s = -1;
        for(int i=0; i < 1024; i++){
            if(memory[i] == false){

                c++;
                if(s == -1){ s=i;}

                if(c == space){
                    allocate(s, i);
                    break;
                }

            }else {s = -1;c=0; continue;}
        }
        if(c != space) {System.out.println("MEMORY NOT AVAILABLE"); return false;}
        return true;
    }

    public boolean deallocate(int pid){
        Process p = null;
        for (Process item : ledger) {   
            if(item.pid == pid){p = item; item.status = false; break;}
        }


        clear(p.s,p.e);
        return false;
    }


    public boolean clear(int start,int end){
        for(int i=start; i <= end; i++){
            memory[i] = false;
        }
        return true;
    }
    public boolean clearAll(){
        for(int i=0; i < 1024; i++){
            memory[i] = false;
        }
        return true;
    }










    public static void main(String[] args) {
        UI ui = new UI();
        ui.FirstFitAllocation(3);
        ui.FirstFitAllocation(6);
        ui.FirstFitAllocation(9);
        ui.FirstFitAllocation(4);
        ui.deallocate(2);

        char c = 'y';
        while(c=='y'){
            

            Scanner sc = new Scanner(System.in);
            System.out.println("Printing Memory...");
            ui.displayMemory();
        
            System.out.print("\nAll Available PIDs : [ ");
            for (Process item : ui.ledger) {   
                if(item.status){
                    System.out.print(item.pid + " ");
                }
            }
            System.out.print(" ] \n");



            System.out.println("\n\n1 for Allocation, 2 for deallocation, other num for Exit : ");
            int choice = sc.nextInt();
            if(choice == 1){
                System.out.print("Please enter size of new memory");
                int s = sc.nextInt();
                if(ui.FirstFitAllocation(s)){

                }else{
                    System.out.println("Allocation Failed");
                }

            }else if(choice == 2){
                System.out.print("Please enter PID to delete : ");
                int s = sc.nextInt();
                ui.deallocate(s);
            }else{
                System.out.println("Thank You.");
                break;
            }
        }
        
    }
}