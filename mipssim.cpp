//
//  main.cpp
//  mipssim
//
//
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <bitset>
#include <stdint.h>
#include <unordered_map>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

struct instruction {
    int opcode, v, rs, rt, rd, shamt, func, imm, asInt, addr, label, breakStart, dest = -1, src1 = -1, src2 = -1, stop=0;
    unsigned int asUint;
    string instr, out;
    
    
    bool isBreak;
    instruction(){ };
    instruction(int i, int address, int start): isBreak(false)
    {
       ;
        asInt = i;
        stop =0;
        asUint = (unsigned int)i;
        v = asUint >> 31;
        out = bitset<32>(asInt).to_string();
        addr = address;
        opcode = asUint >> 26;
        func = asUint << 26 >> 26;
        rs = asUint << 6 >> 27;
        rt = asUint << 11 >> 27;
        rd = asUint << 16 >> 27;
        shamt = asUint << 21 >> 27;
        imm = (signed int) asUint << 16 >> 16;
        label = imm * 4;
        stringstream ss1;
        
        // if bool is true ss1<< asInt; instr == str(); out+= instr
        
        
        
       if (v == 0 && isBreak == false) {
            instr = "Invalid Instruction";
           
            
        }
       
        else if (opcode == 40) {
            ss1 << "ADDI" << right << setw(5) << "\tR" <<  rt << ", R" << rs << ", #" << imm;
            instr = ss1.str();
            dest = rt;
            src1 = rs;
            src2= rs;
        }
        else if (opcode == 43) {
            stringstream ss1;
            ss1 << "SW"<< right << setw(5) << "\tR" << rt << ", " << imm << "(R" << rs << ")";
            instr = ss1.str();
            src1 = rs;
            src2= rs;        }
        else if (opcode == 35) {
            stringstream ss1;
            ss1 << "LW" << right << setw(5) << "\tR" << rt << ", " << imm << "(R" << rs << ")";
            instr = ss1.str();
        }
        else if (opcode == 33) {
            stringstream ss1;
            ss1 << "BLTZ" << right << setw(5) << "\tR" << rs << ", #" << label;
            instr = ss1.str();
        }
        else if (opcode == 4) {
            stringstream ss1;
            ss1 << "BEQ" << right << setw(5) << "\tR" << rs << ", R" << rt<< ", #" << label;
            instr = ss1.str();
        }
        else if (func == 2 && opcode == 32) {
            stringstream ss1;
            ss1 << "SRL" << right << setw(5) << "\tR" << rd << ", R" << rt << ", #" << shamt;
            instr = ss1.str();
        }
        else if (opcode == 60) {
            stringstream ss1;
            ss1 << "MUL" << right << setw(5) << "\tR"<< rd << " ,R" << rs << ", R" << rt;
            instr = ss1.str();
        }
        else if (func == 10) {
            stringstream ss1;
            ss1 << "MOVZ" << right << setw(5) << "\tR"<< rd << " ,R" << rs << ", R" << rt;
            instr = ss1.str();
        }
        else if (func == 0 && opcode == 32) {
            stringstream ss1;
            ss1 << "SLL" << right << setw(5) << "\tR" << rd << ", R" << rt << ", #" << shamt;
            instr = ss1.str();
        }
        if (opcode == 32 && rd == 0 && rt == 0 && func == 0) {
            stringstream ss1;
            ss1 << "NOP";
            instr = ss1.str();
        }
        else if (func == 8 && opcode == 32) {
            stringstream ss1;
            ss1 << "JR" << right << setw(5) << "\tR" << rs;
            instr = ss1.str();
        }
        else if (func == 34) {
            stringstream ss1;
            ss1 << "SUB" << right << setw(5) << "\tR" << rd << ", R" << rs << ", R" << rt;
            instr = ss1.str();
        }
        else if (opcode == 34) {
            stringstream ss1;
            ss1 << "J" << right << setw(5) << "\t#" << label;
            instr = ss1.str();
        }
        else if (func == 32&& opcode ==32) {
            stringstream ss1;
            ss1 << "ADD" << right << setw(5) << "\tR" << rd << ", R" << rs << ", R" << rt;
            instr = ss1.str();
        }
        else if (func == 36 && opcode == 0) {
            stringstream ss1;
            ss1 << "AND" << right << setw(5) << "\tR" << rd << ", R" << rs << ", R" << rt;
            instr = ss1.str();
        }
        else if (func == 37) {
            stringstream ss1;
            ss1 << "OR" << right << setw(5) << "\tR" << rd << ", R" << rs << ", R" << rt;
            instr = ss1.str();
        }
        else if ((func == 13)&&(opcode ==32)) {
            isBreak=true;
            stringstream ss1;
            stop++;
            ss1 << "BREAK";
            instr = ss1.str();
       
           
            
        }
        else if(asUint == -1){
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == -2) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == -3) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == -4) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == -5) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == -6) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == -7) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == -8) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == -9) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 1) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 2) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 3) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if(asUint == 0) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        
        else if (asUint == 4) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 5) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 6) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 7) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 8) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 9) {
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 16) {    /// check this is added for final
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 20) {    /// check this is added for final
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
        else if (asUint == 12) {    /// check this is added for final
            stringstream ss1;
            ss1 << asInt;
            instr = ss1.str();
        }
      
        
        
        {
            stringstream ss1;
            ss1 << v << " " << out.substr(1, out.size() - 27) << " " << out.substr(6, out.size() - 27) << " " << out.substr(11, out.size() - 27);
            ss1 << " " << out.substr(16, out.size() - 27) << " " << out.substr(21, out.size() - 27) << " " << out.substr(26, out.size() - 26);
            ss1 << " " << addr << "\t" << instr;
            out = ss1.str();
        }
    }

};

int main(int argc, char* argv[])
{
    char buffer[4];
    int i;
    char* iPtr;
    iPtr = (char*)(void*)&i;
    unordered_map< int, instruction> MEM;
    int addr = 96;
    int breakEnd = 0;
    int breakStart = 0;
    int amt = 4;
    int FD = open(argv[2], O_RDONLY);
    string prefix (argv[4]);
    ofstream Dis(prefix + "_dis.txt");
    ofstream Sim(prefix + "_sim.txt");
    ofstream Pipeline(prefix + "_pipeline.txt");
    //string inFile = "";
    
//    if (argc == 3){
//        inFile = argv[2];
//    }
    
    //int cycleCounter;
    //ifstream File(inFile, ifstream::binary);

    // int FD = open("test1.bin", O_RDONLY);
    //File.open(inFile, ifstream::binary);
    
   
    while (amt != 0)
    {
        amt = read(FD, buffer, 4);
        if (amt == 4)
        {
            iPtr[0] = buffer[3];
            iPtr[1] = buffer[2];
            iPtr[2] = buffer[1];
            iPtr[3] = buffer[0];
//            cout << "i = " << hex << i << endl;
            instruction I(i, addr, breakStart);
            if (I.func == 13) {
            breakStart = I.addr +4;
            }
            cout << I.out << endl;
            Dis << I.out << endl;
//            cout << "op code: " << dec << (((unsigned int)i) >> 26) << endl;
//            cout << "rs bits: " << ((((unsigned int)i) << 6) >> 27) << endl;
            MEM[addr] = I;
            addr += 4;
            //cycleCounter++;
        }
        //if (addr > 264) exit(0);
        if (amt == 0){
            //amt = 0;
            breakEnd = addr-4;
            //cout << breakEnd;
           
            //cout << breakStart;
        }
        
//        if(Break = true){
//            breakStart = addr;
//        }
    }
    //File.close();
    Dis.close();
    struct processor{
        int PC = 96, cycle = 1, R[32] = {0};
        unordered_map< int, instruction> MEM;
        int preIssue[4] = {0};
        int preALU[2] = {0};
        int preMEM[2] = {0};
        int issueCounter =0;
        int helper = 0;
        
        struct postThings{
            int instr=0, value=0;
        };
        postThings postALU, postMEM;
        void print (const instruction &I, ofstream &Sim, int breakStart, int breakEnd, unordered_map < int, instruction >&MEM){ // break start, break end, unordered_map < int, instruction >& MEM // pass in <--
            stringstream ss1;
            ss1 << "====================\ncycle:" << cycle << "\t"<<
                PC << "\t" << I.instr << "\n\nregisters:";
            for (int i = 0; i < 32; i++){
                if (i %8 == 0) ss1 << "\nr" << setw(2) << setfill('0') << i << ":";   /// i = start of break; i<= end of break; i+= 4
                ss1 << "\t" << R[i];
            }
            ss1 << "\n\n" << "data:";
            for (int i = breakStart; i <= breakEnd; i+=4){
                if (((i - breakStart)/4) %8 == 0) ss1 << "\n" << setw(2)<< setfill('0')<< i << ":";   /// i = start of break; i<= end of break; i+= 4
                ss1 << "\t" << MEM[i].asInt;
            }
            ss1 << "\n";
            cout << ss1.str() << endl;
            Sim << ss1.str() << endl;
        }
        void printState(const instruction &I, ofstream&Pipeline, int breakStart, int breakEnd, unordered_map < int, instruction >&MEM){
            stringstream ss1;
            int counter = 0;
            
            ss1 << "--------------------\nCycle:" << "\t" << cycle << "\t" << "\n\nPre-Issue Buffer:";
            
         
            //MEM[preMEM[0]].rt;
            //"\t"<<PC<< "\t"<<preIssue[0]<<preIssue[1]<<preIssue[2]<<preIssue[3] <<"\t"<< preMEM[0];
            for(int i =0; i<4; i++){
                if (preIssue[i]!=0){
                    if(counter<2){
                        ss1 << "\n\t\tEntry " << i << ": " <<"\t" << MEM[preIssue[i]].instr;
                        //MEM[preIssue[i]].opcode ;
                        counter++;
                    }else{
                        ss1 << "\n\t\tEntry " << i << ": ";
                    }
                }
                if(preIssue[i]==0){
                    ss1 << "\n\t\tEntry " << i << ": ";
                }
            }
            
            ss1 << "\n\nPre_ALU Queue:";
            for(int i =0; i<2; i++){
                if (preALU[i]!=0){
                    ss1 << "\n\t\tEntry " << i << ": " <<"\t" << MEM[preALU[i]].instr;
                    //MEM[preIssue[i]].opcode ;
                    counter++;
                }else{
                    ss1 << "\n\t\tEntry " << i << ": ";
                }

        }
            
            
            ss1 << "\nPost_ALU Queue:";
            for(int i =0; i<1; i++){
                if (postALU.value!=0){
                    ss1 << "\n\t\tEntry " << i << ": " <<"\t" << MEM[postALU.value].instr;
                    //MEM[preIssue[i]].opcode ;
                    counter++;
                }else{
                    ss1 << "\n\t\tEntry " << i << ": ";
                }
        }
            
            
            
            
            ss1<< "\nPre_MEM Queue:";
            for(int i =0; i<2; i++){
                if (preMEM[i]!=0){
                    ss1 << "\n\t\tEntry " << i << ": " <<"\t" << MEM[preMEM[i]].instr;
                    //MEM[preIssue[i]].opcode ;
                    counter++;
                }else{
                    ss1 << "\n\t\tEntry " << i << ": ";
                }

        }
            
            
            
            ss1<< "\nPost_MEM Queue:";
            for(int i =0; i<1; i++){
                if (postMEM.value!=0){
                    ss1 << "\n\t\tEntry " << i << ": " <<"\t" << MEM[postMEM.value].instr;
                    //MEM[preIssue[i]].opcode ;
                    counter++;
                }else{
                    ss1 << "\n\t\tEntry " << i << ": ";
                }
        }
            
            
            ss1 << "\n\nRegisters:";
            for (int i = 0; i < 32; i++){
                if (i %8 == 0) ss1 << "\nR" << setw(2) << setfill('0') << i << ":";
                ss1 << "\t" << R[i];
            }
            
            ss1<< "\n\nData\n";
            //breakStart << ":"<< "\t" ;
            // MEM[breakStart].asInt <<"\t\t"<< MEM[breakEnd].asInt;
//            ss1<< "\n" << "--------------------";
            for (int i = breakStart; i <= breakEnd; i+=4){
                if (((i - breakStart)/4) %8 == 0) ss1 << "\n" << setw(2)<< setfill('0')<< i << ":";   /// i = start of break; i<= end of break; i+= 4
                ss1 << "\t" << MEM[i].asInt;
            }
            cout << ss1.str() << endl;
            Pipeline << ss1.str() << endl;
            
        }
        bool XBWcheck( int reg, int issuePos ){
            if( reg <0 ) return false;
            for( int i = issuePos-1; i >=0; i-- ){
                if( reg == MEM[preIssue[i]].dest ) return true;
            }
            for( int i = 0; i < 2; i++ ){
                if( reg == MEM[preALU[i]].dest ) return true;
                if( reg == MEM[preMEM[i]].dest ) return true; // dest == rt
            }
            if( reg == MEM[postALU.instr].dest ) return true;
            if( reg == MEM[postMEM.instr].dest ) return true;
            return false;
        }
        void WB(){
            helper = preIssue[0]+ preIssue[1]+preIssue[2]+preIssue[3]+preMEM[0]+preMEM[1]+preALU[0]+preALU[1]+postALU.value+postMEM.value;
            if( postMEM.instr !=0 ) {
                R[ MEM[postMEM.instr].dest ] = postMEM.value;
                postMEM = postThings();
            }
            if( postALU.instr !=0 ) {
                R[ MEM[postALU.instr].dest ] = postALU.value;
                postALU = postThings();
            }
        }
        void IF(){
            instruction I = MEM[PC];
            int count = 0;
            int issuePos = 0; //
            helper = preIssue[0]+ preIssue[1]+preIssue[2]+preIssue[3]+preMEM[0]+preMEM[1]+preALU[0]+preALU[1]+postALU.value+postMEM.value;
            
         
            for( int i = 0; i < 4; i++ ){
                if((MEM[PC].opcode == 32)&&(MEM[PC].func == 13)){
                    preIssue[i]=0;
                    PC=PC-4;   //func 13
                    //invalid // break
                    return;
                }
                if (preIssue[0] == 0){
                    if(preIssue[1] != 0){
                        preIssue[0] = preIssue[1]; //move pos 1 to pos 0
                        preIssue[1] = 0;   //empty pos[1] in preIssue array
                        PC =PC -4;
                    }
                    if (preIssue[2] != 0){
                        preIssue[1] = preIssue[2]; //move pos 2 to pos 1
                        preIssue[2] = 0;   //empty pos[2] in preIssue array
                        PC =PC -4;
                    }
                    if (preIssue[3] != 0){
                        preIssue[2] = preIssue[3]; //move pos 3 to pos 2
                        preIssue[3] = 0;   //empty pos[3] in preIssue array
                        PC =PC -4;
                    }
                }
               
                if((MEM[PC].opcode == 35 ) && (preIssue[i] == 0)){
                    preIssue[i]= PC;  //lw
                    issuePos = i;
                }
                if((MEM[PC].opcode == 40 ) && ( preIssue[i] == 0)){
                    preIssue[i]= PC; //addi
                    issuePos = i;
                }
                if((MEM[PC].opcode == 32 && MEM[PC].func == 32) && ( preIssue[i] == 0)){
                    preIssue[i]= PC; //add
                    issuePos = i;
                }
                if((MEM[PC].opcode == 43 ) && ( preIssue[i] == 0)){
                    preIssue[i]= PC; //sw
                    issuePos = i;
                }
                if((MEM[PC].opcode == 34 ) && ( preIssue[i] == 0)){
                    //j
                    preIssue[i]= 0;
                }
                if((MEM[PC].opcode == 33 ) && ( preIssue[i] == 0)){
                    //bltz
                    preIssue[i]= 0;
                }
                if((MEM[PC].opcode == 0 ) && ( preIssue[i] == 0)){
                    //invalid
                    preIssue[i]= 0;
                }
               
                PC+=4;
                count++;
                if(count>=2){
                    i=4;
                    if(issuePos==0){
                        PC=PC-4;
                        return;
                    }
                }
//vvv if there is a lw in pre mem it has to be executed before a sw can go
                if(
                   (
                       (
                           (MEM[preMEM[0]].opcode == 35) && (MEM[preIssue[0]].opcode == 43)
                       ) || (
                           (MEM[preIssue[1]].opcode == 43)
                       ) || (
                           (MEM[preIssue[2]].opcode == 43)
                       ) || (
                           (MEM[preIssue[3]].opcode == 43)
                       )
                   )
                   ){
                    return;
                }
            }
            if( XBWcheck( I.src1, issuePos ) || XBWcheck( I.src2, issuePos ) ) preIssue[issuePos] = 0;   // remove from pre-issue if hazard detected
        }
        
        void ISSUE(){
            instruction I = MEM[PC];
            issueCounter =0;
            helper = preIssue[0]+ preIssue[1]+preIssue[2]+preIssue[3]+preMEM[0]+preMEM[1]+preALU[0]+preALU[1]+postALU.value+postMEM.value;
            
            // *** Maybe change case of if sw is present when lw is working return to if a sw and lw have same register then return***
            
            if(
               (
                   (
                       (MEM[preMEM[0]].opcode == 35) && (MEM[preIssue[0]].opcode == 43)
                   ) || (
                         (MEM[preMEM[0]].opcode == 35) && (MEM[preIssue[1]].opcode == 43)
                   ) || (
                         (MEM[preMEM[0]].opcode == 35) &&(MEM[preIssue[2]].opcode == 43)
                   ) || (
                         (MEM[preMEM[0]].opcode == 35) &&(MEM[preIssue[3]].opcode == 43)
                   )
               )
               ){
                return;
            }
            
            
            if(postMEM.value!=0){
                return;
            }
            
            if(postALU.value!=0){
                return;
            }
                if (((MEM[preIssue[0]].opcode) == 35) &&(issueCounter==0)){
                    //lw should go to preMem
                    
                    if (preMEM[0]==0){
                        //if the first preMEM array spot is empty
                        preMEM[0] = preIssue[0];
                        preIssue[0] = 0;
                        issueCounter++;
//
                    }
                    if ((preMEM[0]!=0)&&(preMEM[1]==0)&&(issueCounter ==0)){
                        //if the first preMEM array spot is full but the second is empty
                        preMEM[1] = preIssue[0];
                        preIssue[0] = 0;
                        issueCounter++;
                     
                    }
                }
            
            //--------^lw^---------------
                    if (((MEM[preIssue[0]].opcode) == 43)&&(issueCounter==0)){
                        //sw should go to preMem
                        
                        if (preMEM[0]==0){
                            
                            //if the first preMEM array spot is empty
                            preMEM[0] = preIssue[0];
                            preIssue[0] = 0;
                            issueCounter++;
//
                    }
                        if ((preMEM[0]!=0)&&(preMEM[1]==0)&&(issueCounter ==0)){
                            //if the 2nd preMEM array spot is empty
                            
                            preMEM[1] = preIssue[0];
                            preIssue[0] = 0;
                            issueCounter++;
                        }
                }
            //-----------^sw^----------------
            if (((MEM[preIssue[0]].opcode) == 40 )&& (issueCounter==0)){
                //addi should go to preALU
                if (preALU[0]==0){
                    //if the first preMEM array spot is empty
                    preALU[0] = preIssue[0];
                    preIssue[0] = 0;
                    issueCounter++;
            }
                if ((preALU[0]!=0)&&(preALU[1]==0)&&(issueCounter ==0)){
                    //if the 2nd preMEM array spot is empty
                    
                    preMEM[1] = preIssue[0];
                    preIssue[0] = 0;
                    issueCounter++;
                }
        }
            //----------^addi^---------------------------
            if (((MEM[preIssue[0]].opcode) == 32 )&& (issueCounter==0)){
                //add should go to preALU
                if (preALU[0]==0){
                    
                    //if the first preMEM array spot is empty
                    preALU[0] = preIssue[0];
                    preIssue[0] = 0;
                    issueCounter++;

            }
                if ((preALU[0]!=0)&&(preALU[1]==0)&&(issueCounter ==0)){
                    //if the 2nd preMEM array spot is empty
                    
                    preMEM[1] = preIssue[0];
                    preIssue[0] = 0;
                    issueCounter++;
                }
        }
            

            //----------^add^------------------------------
            
                // needs to sort pre-issue stuffs to either pre_alu or pre_mem
                // lw/sw go to pre_mem and add/addi go to pre_alu
                //only sorts one instruction at a time i think, then postion in preissue needs to be updated
                // so something like if MEM[preIssue[0]].opcode is a lw/sw, then goes to a preMem sort.
                // preMem sort would be out of two postitions, if preMEM[0] == 0 && preMEM[1] == 0, sort to first, preMEM[0]
                // then set preMEM[0] = preIssue[0]; then remember if preIssue[1]/[2]/[3] !=0 then move them all over so that 0, 1, 2 are filled and 3 is set to 0
                
            
            //CURRENT CODE MIGHT HAVE BUG where if an instruction gets placed and updated then it can loop further and overwrite maybe*BUG MIGHT BE SOLVED*
            }
        void ALU(){
        instruction I = MEM[PC];
            helper = preIssue[0]+ preIssue[1]+preIssue[2]+preIssue[3]+preMEM[0]+preMEM[1]+preALU[0]+preALU[1]+postALU.value+postMEM.value;
          // i think this needs to sort pre_alu to post_alu queue, not sure if it actually calculates or if all the calculating is just for cache
            if (preALU[0]!=0){         // if preALU[0] is queued up and there are no new issues loaded send to postalu
                postALU.value = preALU[0];                  //might need to be changed to different critera
                preALU[0] = 0;                              //set pre to post then adjust position of pre vals
                if ((preALU[0]=0)&&(preALU[1]!=0)){
                    preALU[0]=preALU[1];
                    preALU[1]=0;
                }
                return;
        }
            if(postALU.value !=0){
                postALU.value =0;
                return;    //if item in postALU already, then execute function. if criteria probably needs to be changed
            }
            }
        void MEMORY(){
        instruction I = MEM[PC];
            helper = preIssue[0]+ preIssue[1]+preIssue[2]+preIssue[3]+preMEM[0]+preMEM[1]+preALU[0]+preALU[1]+postALU.value+postMEM.value;
            
            
          // i believe this is supposed to just send to post mem but i have no idea bc MEM is the name of the ordered map
            if(MEM[preMEM[0]].opcode ==43 ){
                preMEM[0]=0;                            //if sw skip post and execute immediately
                if ((preMEM[0]=0)&&(preMEM[1]!=0)){
                    preMEM[0]=preMEM[1];
                    preMEM[1]=0;
                }
                return;
            }

            if (preMEM[0]!=0){         // if preMEM[0] is queued up and there are no new issues loaded send to postMEM
                postMEM.value = preMEM[0];                  //might need to be changed to different critera
                
                // initialize instruction to update proper registers if need be
                
                preMEM[0] = 0;                              //set pre to post then adjust position of pre vals
                if ((preMEM[0]=0)&&(preMEM[1]!=0)){
                    preMEM[0]=preMEM[1];
                    preMEM[1]=0;
                }
                return;
        }
            if(postMEM.value !=0){
                postMEM.value =0;
                return;    //if item in postMEM already, then execute function. if criteria probably needs to be changed
            }
          
            }
     
    };
    
    //pipeline
    
            //break;
        
//    }
    
    
    
    
    
    
    
    //simulator
    processor P;
    while (true){
        instruction I = MEM[P.PC];
      
            //processor state;
        //while(P[I.stop])
            P.MEM = MEM;
            //instruction I = MEM[P.PC];
        
//            P.WB();
//            P.ALU();
//            P.MEMORY();
//            P.ISSUE();
//            P.IF();
//            P.printState(I, Pipeline, breakStart, breakEnd,MEM);
        
        
        
        
        
        
        //instruction I = MEM[P.PC];
        while (I.v == 0){ // skips if invalid instruction
            P.PC += 4;
            I = MEM[P.PC];
        }
        if(I.opcode == 40){
            //addi
            P.R[I.rt] = P.R[I.rs] + I.imm;
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
        }
        else if (I.opcode == 43){
            // sw
            MEM[I.imm + P.R[I.rs]].asInt = P.R[I.rt];
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
        }
        else if (I.opcode == 35) {
            //lw
            P.R[I.rt] = MEM[P.R[I.rs]+ I.imm].asInt;
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
        }
        else if (I.opcode == 33) {
            // BLTZ
            if(P.R[I.rs] < 0) {
                P.print (I, Sim, breakStart, breakEnd, MEM);
                P.PC +=  I.label+4;
                P.cycle ++;
                //I = MEM[P.PC];
            }else{
                P.print (I, Sim, breakStart, breakEnd, MEM);
                P.PC += 4;
                P.cycle ++;
               // I = MEM[P.PC];
                
            }
        }
        else if (I.func == 0 && I.opcode == 32) {
            //SLL
            P.R[I.rd] = (P.R[I.rt] << (I.shamt));
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
        }
        else if (I.opcode == 32 && I.rd == 0 && I.rt == 0 && I.func == 0) {
            //nop
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
            I = MEM[P.PC];
            
        }
        else if (I.func == 8 && I.opcode == 32) {
            //jr
            //ss1 << "JR" << right << setw(5) << "\tR" << rs;
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC = P.R[I.rs];
            P.cycle ++;
            I = MEM[P.PC];
        }
        else if (I.func == 34) {
           //sub
            //ss1 << "SUB" << right << setw(5) << "\tR" << rd << ", R" << rs << ", R" << rt;
            P.R[I.rd] = P.R[I.rs] - P.R[I.rt];
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
        }else if (I.opcode == 34) {
           // j
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC = I.label;
            P.cycle ++;
            //I = MEM[P.PC];
            
          
            //ss1 << "J" << right << setw(5) << "\t#" << label;
        } else if (I.func == 32) {
          //add
            //ss1 << "ADD" << right << setw(5) << "\tR" << rd << ", R" << rs << ", R" << rt;
            P.R[I.rd] = P.R[I.rs] + P.R[I.rt];
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
           
        } else if (I.func == 36 && I.opcode == 0) {
            // AND
            //ss1 << "AND" << right << setw(5) << "\tR" << rd << ", R" << rs << ", R" << rt;
            P.R[I.rd] = P.R[I.rs] & P.R[I.rt];
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
        } else if (I.func == 37) {
            //or
           // ss1 << "OR" << right << setw(5) << "\tR" << rd << ", R" << rs << ", R" << rt;
            P.R[I.rd] = P.R[I.rs] | P.R[I.rt];
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
        }
        else if (I.func == 10) {
            //movz
            //ss1 << "MOVZ" << right << setw(5) << "\tR"<< rd << " ,R" << rs << ", R" << rt;
            if (P.R[I.rs] == 0){
                P.R[I.rd] = (P.R[I.rt]);
            }
            else if (P.R[I.rt] == 0){
                P.R[I.rd] = (P.R[I.rs]);
            }
        
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
           
        }
        else if (I.func == 2 && I.opcode == 32) {
           //srl
            //ss1 << "SRL" << right << setw(5) << "\tR" << rd << ", R" << rt << ", #" << shamt;
            P.R[I.rd] = (P.R[I.rt] >> I.shamt);
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
            
        }
        else if (I.opcode == 60) {
           //mul
            //ss1 << "MUL" << right << setw(5) << "\tR"<< rd << " ,R" << rs << ", R" << rt;
            P.R[I.rd] = (P.R[I.rs] * P.R[I.rt]);
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
        
    }   else if (I.opcode == 4) {
        // BEQ
        //ss1 << "BEQ" << right << setw(5) << "\tR" << rs << ", R" << rt<< ", #" << label;
        if(P.R[I.rs] == P.R[I.rt]) {
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC +=  I.label+4;
            P.cycle ++;
            I = MEM[P.PC];
        }else{
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
            I = MEM[P.PC];}
    }
        
        else if (I.func == 13 && I.opcode ==32) {
            //break
    
            
            P.print (I, Sim, breakStart, breakEnd, MEM);
            P.PC += 4;
            P.cycle ++;
            I = MEM[P.PC];
            Sim.close();
//            while(P.helper!=0){
//                P.WB();
//                P.ALU();
//                P.MEMORY();
//                P.ISSUE();
//                P.IF();
//                P.printState(I, Pipeline, breakStart, breakEnd,MEM);
//            }
      
            //exit(0);
            break;
          
//            exit(0);
        }
      
        //break;
//        else{
//
//           /// remove else once sim is done
//        }
        
//        if ((I.opcode != 34) || (I.opcode != 33)){
//            P.print (I, Sim, breakStart, breakEnd, MEM);
//            P.PC += 4;
//            P.cycle ++;
//        }
//if(P.cycle > 19) exit(0);
        // once all is programmed, do an else to exit and remove above line
    }
    processor state;
    state.MEM = MEM;
    while (true){
        instruction I = MEM[state.PC];
        
        //processor state;
        //while(P[I.stop])
        
        //instruction I = MEM[P.PC];
        
                    state.WB();
                    state.ALU();
                    state.MEMORY();
                    state.ISSUE();
                    state.IF();
                    state.printState(I, Pipeline, breakStart, breakEnd,MEM);
                    state.cycle++;
        if((state.helper==0 && state.cycle>2)||(state.cycle>=45)){
            state.printState(I, Pipeline, breakStart, breakEnd,MEM);
            Pipeline.close();
            exit(0);
        }
    }
    
    return 0;
}

