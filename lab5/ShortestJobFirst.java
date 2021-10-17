import java.util.*;

/*
    Total CPU Time = (system+User+IO+Other) but excluding Idle Time
    // here so, total cpu time will be the summation of burst time of all the jobs


*/
class Job{
    int pid;
    int arrival_time;
    int burst_time;
    Job(int pid,int at, int bt){
        this.pid = pid;
        this.arrival_time = at;
        this.burst_time = bt;
    }
}


public class ShortestJobFirst {
    
    public static void main(String[] args) {
        Random random = new Random();

        System.out.println(" Non Preemptive Algorithm ");
        Scanner sc = new Scanner(System.in);
        ArrayList<Job> jobs = new ArrayList<Job>();
        
        System.out.print("Enter number of processes : ");
        int n = sc.nextInt();

        for(int i=0; i < n; i++){
            jobs.add(new Job(i,random.nextInt(20),random.nextInt(20)));
        }
        


        // for(int i=0; i < total_jobs; i++){
        //     int at,bt;
        //     System.out.print(" Job ID : "+Integer.toString(i+1)+" \n");
        //     System.out.print(" Enter Arrival Time : ");
        //     at = sc.nextInt();
        //     System.out.print(" Enter Burst Time : ");
        //     bt = sc.nextInt();
        //     jobs.add(new Job(i+1,at,bt));
        //     System.out.println("Job "+(i+1)+" Saved\n");
        // }

        int time = 0;
        ArrayList<Job> gc = new ArrayList<Job>();

        Queue<Job> readyQueue = new LinkedList<Job>();

        while(true){

            if(time == 100){
                break;
            }
            int minJob = -1;
            int minBurstTime = Integer.MAX_VALUE;

            for(int i=0; i < jobs.size(); i++){
                if(time >= jobs.get(i).arrival_time){
                    minBurstTime = Math.min(minBurstTime,jobs.get(i).burst_time);
                    if(minBurstTime == jobs.get(i).burst_time){
                        minJob = i;
                    }
                }
            }

            if(minBurstTime == Integer.MAX_VALUE){
                
            }else{
                readyQueue.add(jobs.get(minJob));
                gc.add(jobs.get(minJob));
                jobs.remove(minJob);
            }

            time++;

        }

        
        System.out.println(" Printing Jobs ");

        for(int i=0; i < gc.size(); i++){
            System.out.println(" Job ID = "+gc.get(i).pid + ", Arrival Time = "+gc.get(i).arrival_time + ", Burst Time = "+gc.get(i).burst_time + " \n");
        }
        

        int totalcputime = 0;
        for(Job j: gc){
            totalcputime += j.burst_time;
        }
        System.out.println("Total CPU Time : "+totalcputime);



    }
}