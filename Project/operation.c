/* Here we perform the protein synthesis operation. In funtion operate at first each input is read from reporter mRNA. Then according to input codon and instruction the output is generated and the output peptide chain is created.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <operation.h>
#include <util.h>
#include <input.h>
#include <mrna.h>
#include <ribosome.h>
#include <main1.h>

extern FILE *fpdbio;
extern FILE *fpddig;
extern FILE *fpmrna;
extern FILE *fpp;

/*File pointer for output file*/
extern FILE *fpnop;

/* File pointers for perfromance parameters energy and time*/
extern FILE *fpengy;
extern FILE *fptime;

void *muta_selection(char *codon, ribosome *mutaribo1, int *activatormuta, int *selectormuta){
	int k,l,s,n=0;
	 
	for(k=0;k<mutaribo1->activatorcount;k++){
		for(l=0; l<mutaribo1->mlist[k].acount; l++){
			if(!(strcmp(mutaribo1->mlist[k].activator[l],codon))){
				//printf("Mutation activator %s activates mutation %s\n", mutaribo1->mlist[k].activator[l], mutaribo1->mlist[k].name);
				mutaribo1->mlist[k].stat=1;
				*activatormuta=k;	
			}
		}			
	}
	n = mutaribo1->activatorcount + mutaribo1->selectorcount;
	//printf("The selector mutation count %d\n", n);

	for(s=mutaribo1->activatorcount;s<n;s++){
		for(l=0; l<mutaribo1->mlist[s].acount; l++){
			if(!strcmp(mutaribo1->mlist[s].activator[l], codon)){
				//printf("Mutation activator %s activates mutation %s\n", mutaribo1->mlist[s].activator[l], mutaribo1->mlist[s].name);
				mutaribo1->mlist[s].stat=1;
				*selectormuta=s;
			}
					
		}	
	}	
    return 0;
}				

void elongation(char *opcodon, int option, char *peptidechain){

	if(option == 0){
		if(!strcmp(opcodon, "B_1B_2B_3")){
			strcat(peptidechain, "L");
            fprintf(fpdbio,"%s Append L \t ", opcodon);
		}
		else{

            fprintf(fpdbio,"%s skipped \t ", opcodon);
		}
	}
	else if(option == 1){
		if(!strcmp(opcodon, "B_4B_5B_6")){
			strcat(peptidechain, "A");

            fprintf(fpdbio,"%s \t Append A \t ", opcodon);
		}
		else {

            fprintf(fpdbio,"%s \t skipped \t ", opcodon);
		}
	}
	else if(option == 10){
		if(!strcmp(opcodon, "B_7B_8B_9")){
			strcat(peptidechain, "X");

            fprintf(fpdbio,"%s \t Append X\t",opcodon);
		}
		else{

            fprintf(fpdbio,"%s \t skipped \t ", opcodon);
		}
	}
}

void suppression(char *codon, ribosome *mutaribo2, int s){
	
	if(!(strcmp(codon, "SM_1"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_2"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_3"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_4"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_5"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_6"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_7"))){
        mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_8"))){
        mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_(S_L)"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}
	else if(!(strcmp(codon, "SM_(S_A)"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}
	
	else if(!(strcmp(codon, "SM"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_{S_0}"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}

	else if(!(strcmp(codon, "SM_{S_1}"))){
		mutaribo2->mlist[s].stat=0;
        fprintf(fpdbio,"SM %s by %s\n\n", mutaribo2->mlist[s].name, codon);
	}
	
}

char *operate(mrna *rtmrna, ribosome *mutaribo, int *acti){
    int i=0, c=0, len=0, d=0, m=0, t=0, r=2, flow=0;
    int j;
	char *ip, *result, *activemuta, *op;
	int stall = 0; 
	chain nascent_chain;
	int activated=0, selected=0, flagmuta=0, option=0;
    int gtp, time;
	nascent_chain = (char *) malloc (sizeof(char)*25);

	activemuta = (char *) malloc (sizeof(char)*40);

	op = (char *)malloc(sizeof(char)*40);

	ip = (char *)malloc(sizeof(char)*40);

	strcpy(ip, "");//Initialize ip the input codon holder as a blank string
	strcpy(nascent_chain, "");//Initialize nascent_chain as blank string
	strcpy(activemuta, "");//Initialize ip the input codon holder as a blank string
    //acti = &flow;
	gtp=3;
    time = 0;

    fprintf(fpdbio,"\n\n*********************************************   Details of the execution of mRNA id : %s *********************************************\n",(*rtmrna)[0]);

    if (!strcmp((*rtmrna)[i],"SD_multd")){
        flagmuta=1;
    }
    else if (!strcmp((*rtmrna)[i],"SD_divd")){
        flagmuta=1;
    }
    else if(!strcmp((*rtmrna)[i],"SD_multshift")){
        d=2;
    }
    else if(!strcmp((*rtmrna)[i],"SD_divshift")){
        d=2;
        printf("D = %d",d);
    }
    else if(!strcmp((*rtmrna)[i],"SD_quotshift")){
        t=5;
        d=3;
    }
    else if(!strcmp((*rtmrna)[i],"SD_shift")){
        d = 1;
    }

    else if(!strcmp((*rtmrna)[i],"SD_comparator")){
       r=3;
    }

	if(!strcmp((*rtmrna)[i], "SD_and")){
		
		m=2;
	}
	else if(!strcmp((*rtmrna)[i], "SD_or")){
		
		m=2;
	}
	else if(!strcmp((*rtmrna)[i], "SD_xor")){
		
		m=2;
	}

    else if(!strcmp((*rtmrna)[i], "SD_nand")){

        m=2;
    }
    else if(!strcmp((*rtmrna)[i], "SD_nor")){

        m=2;
    }
    else if(!strcmp((*rtmrna)[i], "SD_xnor")){

        m=2;
    }

    else if(!strcmp((*rtmrna)[i], "SD_not")){

        m=2;
    }

    fprintf(fpdbio,"\nmRNA codon %d \t",i);

	for(i=0; strcmp((*rtmrna)[i],"AUG"); i++) ;
	i++;
	gtp= gtp +2 ;
    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
    time = time + 1 ;
    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

    fprintf(fpdbio,"AUG read\n");
    fprintf(fpdbio,"mRNA codon %d \t",i);

    if(!(strcmp((*rtmrna)[i],"Activator_of_M_L^{add}"))){
            activated=0;
            mutaribo->mlist[activated].stat=1;
            printf("Initial mutation %s\n", mutaribo->mlist[activated].name);
            fprintf(fpdbio,"Initial mutation %s\n", mutaribo->mlist[activated].name);
            i++;
            flow=1;
        }

        else if(!(strcmp((*rtmrna)[i],"Activator_of_M_L^{sub}"))){
            activated=0;
            mutaribo->mlist[activated].stat=1;
            printf("Initial mutation %s\n", mutaribo->mlist[activated].name);
            fprintf(fpdbio,"Initial mutation %s\n", mutaribo->mlist[activated].name);
            i++;
            flow=1;
        }

        else if(!strcmp((*rtmrna)[i],"Activator_of_C_1")){
            activated=1;
            mutaribo->mlist[activated].stat=1;
            printf("Initial mutation %s\n", mutaribo->mlist[activated].name);
            fprintf(fpdbio,"Initial mutation %s\n", mutaribo->mlist[activated].name);
            i++;
        }

        else if(!(strcmp((*rtmrna)[i],"C_1C_2C_3"))){
            activated=0;
            mutaribo->mlist[activated].stat=1;
            printf("Initial mutation %s\n", mutaribo->mlist[activated].name);
            fprintf(fpdbio,"Initial mutation %s\n", mutaribo->mlist[activated].name);
            i++;
        }
        else if(!(strcmp((*rtmrna)[i],"M_d^{mult}"))){
            m=1;
            strcpy(activemuta, "M_d^{mult}");
            i++;
        }

        else if(!strcmp((*rtmrna)[i],"Activator_of_M_c^{div}")){
            m=1;
            strcpy(activemuta, "M_c^{div}");
            i++;
        }

        else if(!strcmp((*rtmrna)[i],"Activator_of_M_d^{div}")){
            m=1;
            strcpy(activemuta, "M_d^{div}");
            i++;
        }
        else if(!strcmp((*rtmrna)[i],"Activator_of_CM_1")){
            activated=0;
            mutaribo->mlist[activated].stat=1;
            //strcpy(activemuta, mutaribo->mlist[activated].name);
            printf("Initial mutation %s\n", mutaribo->mlist[activated].name);
            fprintf(fpdbio,"Initial mutation %s\n", mutaribo->mlist[activated].name);
            i++;
        }
    gtp = gtp + 1;
    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
    time = time +1 ;
    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

	for(; strcmp((*rtmrna)[i], "UAA"); i++){ 

        fprintf(fpdbio,"mRNA: %d \t",i);
		if(d==0){
			if(!(strcmp((*rtmrna)[i],"SecM"))){

				gtp=gtp+340;
                fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                time = time + 340 ;
                fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

				stall = 1;

                fprintf(fpdbio,"Stalled \t");
				if(strcmp((*rtmrna)[0], "SD_twoscom") == 0){
					c=1;
				}
				continue;
			}

			if(!(strcmp((*rtmrna)[i],"SecA"))){

				gtp=gtp+1962;
                fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                time = time + 1962 ;
                fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);
				stall = 0;
				t=0;               
                fprintf(fpdbio,"Released \t");
				continue;	
			}
			
		
			/*Stalled ribosome is taken following action*/
			if(stall == 1){
		
				/* If input codon is '0' then attached "B_1B_2B_3" triplet codon to the mRNA*/
				if(!(strcmp((*rtmrna)[i],"B_1B_2B_3"))){
					strcat(ip, "B_1B_2B_3");
					c++;
					gtp++;
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);
				}	

				/* If input codon is '1' then attached "B_4B_5B_6" triplet codon to the mRNA*/
				else if(!(strcmp((*rtmrna)[i],"B_4B_5B_6"))){
					strcat(ip, "B_4B_5B_6");
					c++;
					gtp++;	
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);
				}
				
				if(c==2){
					
					if(m==2)
						strcat(ip, "");
					else{
                        if(m==0){
							strcpy(activemuta, mutaribo->mlist[activated].name);
                        }
						strcat(ip, "+");
						strcat(ip, activemuta);
					}

					muta_selection(ip, mutaribo, &activated, &selected);
                    //printf("Activated %s Selected  %s\t", mutaribo->mlist[activated].name, mutaribo->mlist[selected].name);

                    fprintf(fpdbio,"Activated %s Selected  %s\t", mutaribo->mlist[activated].name, mutaribo->mlist[selected].name);
					
					strcpy(ip, "");/*Set ip as blank string for next input codon reading*/	
					c=0;
					if(flagmuta == 1){

                        fprintf(fpdbio,"\n");
					}

					if(r==3){
						activated = selected;                       
					}	
				}
			}
		
			/*After release the stall ribosome is taken following action*/
			if(stall == 0){
                gtp++;
                fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                time = time + 1 ;
                fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);
                if(t<r){
					strcpy(op, "");
					option = mutaribo->mlist[selected].opt ;
					strcpy(op, (*rtmrna)[i]);
					elongation(op, option, nascent_chain);

					t++;

                    if(t == r)
                        fprintf(fpdbio,"Chain %s \n\n",nascent_chain);
                    //continue;
				}

                /*Supression of activated mutation */
				else {
					strcpy(op, "");
					strcpy(op, (*rtmrna)[i]);
                    suppression(op, mutaribo, selected);

					continue ;
				}
			}
            gtp++;
            fprintf(fpengy, "\n\n");
            fprintf(fptime, "\n\n");

        } /* End of (d=0) type of operation */

		else if(d==1){
			strcpy(op, "");
			if(!(strcmp((*rtmrna)[i], "B_1B_2B_3"))){
				option = 0;
                gtp++;
                fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                time = time + 1 ;
                fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);
			}
			else if(!(strcmp((*rtmrna)[i], "B_4B_5B_6"))){
				option = 1;
                gtp++;
                fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                time = time + 1 ;
                fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);
			}
			strcpy(op, (*rtmrna)[i]);
            fprintf(fpdbio,"The codon for shifting : %s\t", op);

			elongation(op, option, nascent_chain);
            fprintf(fpdbio,"Nascent chain is %s \n",nascent_chain);

            gtp++;
            fprintf(fpengy, "\n\n");
            fprintf(fptime, "\n\n");

        } /* End of (d=1) type of operation */
	
		else if(d==2){

			strcpy(op, "");
			if(!(strcmp((*rtmrna)[i], "B_1B_2B_3"))){
				option = 0;
                gtp++;
                fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                time = time + 1 ;
                fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);
				
			}
			else if(!(strcmp((*rtmrna)[i], "B_4B_5B_6"))){
				option = 1;
                gtp++;
                fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                time = time + 1 ;
                fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);
			}
			strcpy(op, (*rtmrna)[i]);
            fprintf(fpdbio,"The codon for shifting : %s\t", op);

			elongation(op, option, nascent_chain);
            fprintf(fpdbio,"Nascent chain is %s \n",nascent_chain);

            gtp++;
            fprintf(fpengy, "\n\n");
            fprintf(fptime, "\n\n");

        }/* End of (d=2) type of operation */

		else if(d==3){

			strcpy(op, "");
			strcpy(ip, "");
			if(t>1){
				if(!(strcmp((*rtmrna)[i], "G_{Activator}+M_c^{div}"))){					
					strcpy(ip, "G_{Activator}+M_c^{div}");                    
                    fprintf(fpdbio,"The activator codon : %s\t", ip);

                    gtp++;
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

					muta_selection(ip, mutaribo, &activated, &selected);
					strcpy(activemuta, mutaribo->mlist[activated].name);                    
					t++;
					
				}
				else if(!(strcmp((*rtmrna)[i], "G_{Activator}+M_d^{div}"))){
					
					strcpy(ip, "G_{Activator}+M_d^{div}");
                    fprintf(fpdbio,"The activator codon : %s\t", ip);

                    gtp++;
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

					muta_selection(ip, mutaribo, &activated, &selected);
					strcpy(activemuta, mutaribo->mlist[activated].name);

					t++;
					
				}
				else if(!(strcmp((*rtmrna)[i], "G_{Activator}+M_{sub}^{div}"))){
					
					strcpy(ip, "G_{Activator}+M_{sub}^{div}");
                    fprintf(fpdbio,"The activator codon : %s\t", ip);

					muta_selection(ip, mutaribo, &activated, &selected);
					strcpy(activemuta, mutaribo->mlist[activated].name);

                    gtp++;
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

					t++;
					
				}

				else if(!(strcmp((*rtmrna)[i], "B_1B_2B_3"))){

					option = 0;
					strcpy(op, (*rtmrna)[i]);
                    fprintf(fpdbio,"The codon for shifting : %s\t", op);
                    gtp++;
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

					elongation(op, option, nascent_chain);
                   gtp++;

				}
				else if(!(strcmp((*rtmrna)[i], "B_4B_5B_6"))){

					option = 1;
					strcpy(op, (*rtmrna)[i]);
                    fprintf(fpdbio,"The codon for shifting : %s\t", op);
                    gtp++;
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

					elongation(op, option, nascent_chain);
                    gtp++;

				}			

				else if(!(strcmp((*rtmrna)[i], "G_{special}"))){

					strcpy(ip, "G_{special}");
					strcat(ip, "+");
					strcat(ip, activemuta);
                    fprintf(fpdbio,"The special mutation codon for shifting : %s\t", ip);
                    gtp++;
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

					muta_selection(ip, mutaribo, &activated, &selected);
					t = 0;
					continue;
				}
			}
			if(t==0){

				if(!(strcmp((*rtmrna)[i], "SM"))){
					strcpy(op, (*rtmrna)[i]);                   
                    fprintf(fpdbio,"The codon for shifting : %s\t", op);
                    gtp++;
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

					suppression(op, mutaribo, selected);

				}
				
				else {
					option = mutaribo->mlist[selected].opt ;
					strcpy(op, (*rtmrna)[i]);                   
                    fprintf(fpdbio,"The codon for shifting : %s\t", op);
                    gtp++;
                    fprintf(fpengy, "Number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
                    time = time + 1 ;
                    fprintf(fptime, "The consumed time is %d after processing %d th codon in mRNA\n",time,i);

					elongation(op, option, nascent_chain);
                    gtp++;
					
				}
			}	           
            fprintf(fpdbio,"Nascent chain is %s \n",nascent_chain);
            fprintf(fpengy, "\n\n");
            fprintf(fptime, "\n\n");

        } /*End of (d=3) type of operation*/

    } /* End of mRNA string*/

	if(!(strcmp((*rtmrna)[i], "UAA"))){
        fprintf(fpdbio,"\nStop codon UAA is Read\n");

        if(flow == 1){

        fprintf(fpdbio,"Last Activated %s \t", mutaribo->mlist[activated].name);
        if((!(strcmp(mutaribo->mlist[activated].name, "M_A^{add}"))) || (!(strcmp(mutaribo->mlist[activated].name, "M_A^{sub}")))){
                flow=11;

                fprintf(fpdbio, "\nData is overflow\n");
                //fprintf(fpnop, "\nData is overflow\n");
        }
        }
		gtp = gtp+1;	
	}

    gtp++;
    fprintf(fpengy, "*********************=====================********************\n");
    fprintf(fpengy, "\n Finally, the number of GTP is %d after processing %d th codon in mRNA\n",gtp,i);
    fprintf(fpengy, "*********************=====================********************\n\n");
    time = time + 1 ;
    fprintf(fptime, "*********************=====================********************\n");
    fprintf(fptime, "\n Finally the consumed time is %d after processing %d th codon in mRNA\n",time,i);
    fprintf(fptime, "*********************=====================********************\n\n");
	
	
	if(flagmuta ==1){
		result = (char *)malloc(sizeof(char)*20);
		result = mutaribo->mlist[activated].name;

        fprintf(fpdbio,"The final result is %s \t", result);
        fprintf(fpmrna,"The activated mutation is %s \n", result);
	}

	else if(flagmuta ==0){

        fprintf(fpdbio,"Peptide %s\t", nascent_chain);

        fprintf(fpp,"The Peptide chain is : %s\n",nascent_chain);

		len = strlen(nascent_chain);

		result=(char *)malloc(sizeof(char)*len);

		if(d==0){
			if(r == 2){
				for(j=0, i = len-1; j<len; j++, i--){
					if(nascent_chain[i]=='A'){
						result[j] = '1';
					}
					if(nascent_chain[i]=='L'){
						result[j] = '0';
					}
				}
                //if(flow == 1)
                    //result[j++] = ''
                result[j] = '\0';
			}

            /* For comparator the protein chain is returned to the main function */
			else if(r == 3)
				strcpy(result, nascent_chain);

        } /* End of result processing for (d=0) type of operation */

		if(d==1 || d==2 || d==3){
			for(j=0, i=0 ; j<len; j++, i++){
				if(nascent_chain[i]=='A'){
					result[j] = '1';
				}
				if(nascent_chain[i]=='L'){
					result[j] = '0';
				}
			}
            result[j] = '\0';

        } /* End of result processing for (d=1), (d=2) and (d=3) type of operation */

        printf("Result %s \n", result);

        fprintf(fpddig,"\n The output is %s",result);
	}	
     *acti =flow;
	return result;
}


