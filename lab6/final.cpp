#include <bits/stdc++.h>

using namespace std;
struct process {
  int proid;
  int start;
  int end;
  int size;
  bool allocated = false;
  process * next = NULL;
};
struct block {
  int blockid;
  int startadd;
  int endadd;
  block * next = NULL;
};
void firstfit(block * blockhead, process * prochead) 
{
  cout << "\n--------------First fit--------------\n";
  process * proctemp = prochead;
  while (proctemp != NULL) {
    proctemp -> allocated = false;
    block * temp = blockhead;
    // cout << "Checking in blocks\n";
    while (temp != NULL) {
      // cout << "Checking block of id: " << temp->blockid << "\n";
      if ((temp -> endadd) - (temp -> startadd) >= proctemp -> size) {
        proctemp -> start = temp -> startadd;
        proctemp -> end = temp -> startadd + proctemp -> size;
        temp -> startadd = proctemp -> end + 1;
        proctemp -> allocated = true;
        break;
      }
      temp = temp -> next;
    }
    // cout << "Process " << proctemp->proid << "done\n";
    proctemp = proctemp -> next;
  }
  proctemp = prochead;
  cout << "Processid\t" <<
    "Start add\t" <<
    "End add\n";
  while (proctemp != NULL) {
    if ((proctemp -> allocated))
      cout << proctemp -> proid << "\t\t" << proctemp -> start << "\t\t" << proctemp -> end << "\n";
    proctemp = proctemp -> next;
  }
  cout << "Unallocated processes are: ";
  proctemp = prochead;
  while (proctemp != NULL) {
    if (!(proctemp -> allocated))
      cout << proctemp -> proid << " ";
    proctemp = proctemp -> next;
  }
  cout << "\n";
}
void bestfit(block * blockhead, process * prochead) // Allocate memory to processes using best fit method 
{
  cout << "\n--------------Best fit--------------\n";
  process * proctemp = prochead;
  while (proctemp != NULL) {
    proctemp -> allocated = false;
    block * temp = blockhead, * target = NULL;
    // cout << "Checking in blocks\n";
    while (temp != NULL) {
      // cout << "Checking block of id: " << temp->blockid << "\n";
      if (target == NULL && ((temp -> endadd) - (temp ->
          startadd) >= proctemp -> size))
        target = temp;
      else if (((temp -> endadd) - (temp -> startadd) >= proctemp->size) && (((temp -> endadd) - (temp -> startadd)) < ((target -> endadd) - (target ->startadd)))) {
        target = temp;
      }
      temp = temp -> next;
    }
    // cout << "Process " << proctemp->proid << "done\n";
    if (target != NULL) {
      proctemp -> start = target -> startadd;
      proctemp -> end = target -> startadd + proctemp -> size;
      target -> startadd = proctemp -> end + 1;
      proctemp -> allocated = true;
    }
    proctemp = proctemp -> next;
  }
  proctemp = prochead;
  cout << "Processid\t" <<
    "Start add\t" <<
    "End add\n";
  while (proctemp != NULL) {
    if ((proctemp -> allocated))
      cout << proctemp -> proid << "\t\t" << proctemp -> start << "\t\t" << proctemp -> end << "\n";
    proctemp = proctemp -> next;
  }
  cout << "Unallocated processes are: ";
  proctemp = prochead;
  while (proctemp != NULL) {
    if (!(proctemp -> allocated))
      cout << proctemp -> proid << " ";
    proctemp = proctemp -> next;
  }
  cout << "\n";
}
void worstfit(block * blockhead, process * prochead) // Allocate memory to processes using worst fit method 
{
  cout << "\n--------------Worst fit--------------\n";
  process * proctemp = prochead;
  while (proctemp != NULL) {
    proctemp -> allocated = false;
    block * temp = blockhead, * target = NULL;
    // cout << "Checking in blocks\n";
    while (temp != NULL) {
      // cout << "Checking block of id: " << temp->blockid << "\n";
      if (target == NULL && ((temp -> endadd) - (temp ->startadd) >= proctemp -> size))
        target = temp;
      else if (target != NULL && (((temp -> endadd) - (temp ->startadd)) > ((target -> endadd) - (target -> startadd)))) {
        target = temp;
      }
      temp = temp -> next;
      // cout << "Next temp\n";
    }
    // cout << "Process " << proctemp->proid << "done\n";
    if (target != NULL) {
      proctemp -> start = target -> startadd;
      proctemp -> end = target -> startadd + proctemp -> size;
      target -> startadd = proctemp -> end + 1;
      proctemp -> allocated = true;
    }
    proctemp = proctemp -> next;
  }
  proctemp = prochead;
  cout << "Processid\t" <<
    "Start add\t" <<
    "End add\n";
  while (proctemp != NULL) {
    if ((proctemp -> allocated))
      cout << proctemp -> proid << "\t\t" << proctemp ->start << "\t\t" << proctemp -> end << "\n";
    proctemp = proctemp -> next;
  }
  cout << "Unallocated processes are: ";
  proctemp = prochead;
  while (proctemp != NULL) {
    if (!(proctemp -> allocated))
      cout << proctemp -> proid << " ";
    proctemp = proctemp -> next;
  }
  cout << "\n";
}
void rp(block ** blockhead, process ** prochead, int id) // Deleting node from processes and adding or updating node in memory block 
{
  process * proctemp = * prochead, * target = NULL;
  while (proctemp != NULL) {
    if (proctemp -> proid == id) {
      target = proctemp;
      break;
    }
    proctemp = proctemp -> next;
  }
  if (target == NULL) {
    cout << "Process of enterred id is not available\n";
    return;
  }
  if (!(target -> allocated)) {
    cout << "Process is not allocated\n";
    cout << "Can not remove unallocated process\n";
    return;
  }
  block * temp = * blockhead;
  int flag = 0;
  while (temp -> next != NULL) {
    if (target -> start == temp -> endadd + 1) {
      temp -> endadd = target -> end;
      flag = 1;
      break;
    } else if (temp -> startadd == target -> end + 1) {
      temp -> startadd = target -> start;
      flag = 1;
      break;
    }
    temp = temp -> next;
  }
  if (target -> start == temp -> endadd + 1) {
    temp -> endadd = target -> end;
    flag = 1;
  } else if (temp -> startadd = target -> end + 1) {
    temp -> startadd = target -> start;
    flag = 1;
  }
  if (flag == 0) {
    block * temp1 = new block;
    temp1 -> blockid = temp -> blockid + 1;
    temp1 -> startadd = target -> start;
    temp1 -> endadd = target -> end;
    temp -> next = temp1;
    temp1 -> next = NULL;
  }
  proctemp = * prochead;
  if (proctemp -> proid == target -> proid) {
    * prochead = proctemp -> next;
    free(proctemp);
  } else {
    while (proctemp -> next -> proid != target -> proid) {
      proctemp = proctemp -> next;
    }
    proctemp -> next = proctemp -> next -> next;
    free(target);
  }
  cout << "\n--------------Memory Block--------------\n";
  cout << "Block id\t" <<
    "Start add\t" <<
    "End add\n";
  block * wfittemp = * blockhead;
  while (wfittemp != NULL) {
    cout << wfittemp -> blockid << "\t\t" << wfittemp ->startadd << "\t\t" << wfittemp -> endadd << "\n";
    wfittemp = wfittemp -> next;
  }
}
void removeProcess(block ** ffithead, block ** bfithead, block ** wfithead, process ** ffitprochead, process ** bfitprochead, process ** wfitprochead) {
  int id;
  cout << "Enter process id which finishes: ";
  cin >> id;
  cout << "\n--------------First fit--------------\n";
  rp(ffithead, ffitprochead, id);
  cout << "\n--------------Best fit--------------\n";
  rp(bfithead, bfitprochead, id);
  cout << "\n--------------Worst fit--------------\n";
  rp(wfithead, wfitprochead, id);
}
int main() {
  int n;
  cout << "Enter Number of memory block: ";
  cin >> n;
  block * ffithead = new block;
  block * bfithead = new block;
  block * wfithead = new block;
  // Adding memory block using block struct
  int s, e;
  cout << "Enter Starting address and Ending address of memory block " << 1 <<
    " : ";
  cin >> s >> e;
  ffithead -> blockid = 1;
  ffithead -> startadd = s;
  ffithead -> endadd = e;
  ffithead -> next = NULL;
  bfithead -> blockid = 1;
  bfithead -> startadd = s;
  bfithead -> endadd = e;
  bfithead -> next = NULL;
  wfithead -> blockid = 1;
  wfithead -> startadd = s;
  wfithead -> endadd = e;
  wfithead -> next = NULL;
  block * ffittemp = ffithead, * bfittemp = bfithead, * wfittemp = wfithead;
  for (int i = 1; i < n; i++) {
    cout << "Enter Starting address and Ending address of memory block " << i + 1 << " : ";
    cin >> s >> e;
    block * temp1 = new block, * temp2 = new block, * temp3 = new block;
    temp1 -> blockid = i + 1;
    temp1 -> startadd = s;
    temp1 -> endadd = e;
    temp2 -> blockid = i + 1;
    temp2 -> startadd = s;
    temp2 -> endadd = e;
    temp3 -> blockid = i + 1;
    temp3 -> startadd = s;
    temp3 -> endadd = e;
    ffittemp -> next = temp1;
    ffittemp = ffittemp -> next;
    ffittemp -> next = NULL;
    bfittemp -> next = temp2;
    bfittemp = bfittemp -> next;
    bfittemp -> next = NULL;
    wfittemp -> next = temp3;
    wfittemp = wfittemp -> next;
    wfittemp -> next = NULL;
  }
  ffittemp = NULL;
  bfittemp = NULL;
  wfittemp = NULL;
  cout << "\n--------------Memory Block--------------\n";
  cout << "Block id\t" <<
    "Start add\t" <<
    "End add\n";
  wfittemp = wfithead;
  while (wfittemp != NULL) {
    cout << wfittemp -> blockid << "\t\t" << wfittemp ->startadd << "\t\t" << wfittemp -> endadd << "\n";
    wfittemp = wfittemp -> next;
  }
  int pno;
  process * ffitprochead = new process;
  process * bfitprochead = new process;
  process * wfitprochead = new process;
  cout << "Enter number of processes: ";
  cin >> pno;
  int size;
  cout << "Enter size of the processes: ";
  cin >> size;
  ffitprochead -> proid = 1;
  ffitprochead -> size = size;
  bfitprochead -> proid = 1;
  bfitprochead -> size = size;
  wfitprochead -> proid = 1;
  wfitprochead -> size = size;
  process * ffittempproc = ffitprochead, * bfittempproc = bfitprochead, * wfittempproc = wfitprochead;
  for (int i = 1; i < pno; i++) {
    cin >> size;
    process * temp1 = new process;
    process * temp2 = new process;
    process * temp3 = new process;
    temp1 -> proid = i + 1;
    temp1 -> size = size;
    temp2 -> proid = i + 1;
    temp2 -> size = size;
    temp3 -> proid = i + 1;
    temp3 -> size = size;
    ffittempproc -> next = temp1;
    ffittempproc = ffittempproc -> next;
    bfittempproc -> next = temp2;
    bfittempproc = bfittempproc -> next;
    wfittempproc -> next = temp3;
    wfittempproc = wfittempproc -> next;
  }
  ffittempproc = NULL;
  cout << "Processes taken\n";
  // First fit
  firstfit(ffithead, ffitprochead);
  // Best fit
  bestfit(bfithead, bfitprochead);
  // Worst fit
  worstfit(wfithead, wfitprochead);
  int opt;
  cout << "1. Finishes a process by id\n";
  cout << "2. Quit\n";
  cout << "Select option: ";
  cin >> opt;
  switch (opt) {
  case 1:
    removeProcess( & ffithead, & bfithead, & wfithead, & ffitprochead, & bfitprochead, & wfitprochead);
    break;
  default:
    break;
  }
  // Free nodes of linked list
  block * temp = ffithead;
  while (temp != NULL) {
    block * temp1 = temp;
    temp = temp -> next;
    free(temp1);
  }
  temp = bfithead;
  while (temp != NULL) {
    block * temp1 = temp;
    temp = temp -> next;
    free(temp1);
  }
  temp = wfithead;
  while (temp != NULL) {
    block * temp1 = temp;
    temp = temp -> next;
    free(temp1);
  }
  ffittempproc = ffitprochead;
  while (ffittempproc != NULL) {
    process * temp1 = ffittempproc;
    ffittempproc = ffittempproc -> next;
    free(temp1);
  }
  bfittempproc = bfitprochead;
  while (bfittempproc != NULL) {
    process * temp1 = bfittempproc;
    bfittempproc = bfittempproc -> next;
    free(temp1);
  }
  wfittempproc = wfitprochead;
  while (wfittempproc != NULL) {
    process * temp1 = wfittempproc;
    wfittempproc = wfittempproc -> next;
    free(temp1);
  }
  return 0;
}