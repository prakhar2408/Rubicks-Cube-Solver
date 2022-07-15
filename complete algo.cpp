#include<bits/stdc++.h>
using namespace std;

int axis[] ={-3,1,2,-2,-1,3};// 1-x 2-y 3-z

//it contains color and facing of that color of a particular block
struct block{
	vector< vector<int> > color;
	
};
//contains v1=coordinates; v2=facing eg-it tells us about the block red and green whose index is [1][2] and [2][4] seperately(both having same coordinates but different face).
struct face_matrix{
	vector<int> v1;//block_pos
	vector<int> v2;//facing
	
};

block b[3][3][3];
	face_matrix fmat[6][9];
	int cube[6][3][3]={
						{
							{2, 1, 3},
							{4, 0, 3},
							{1, 4, 2}
						},
		  			  {
						{5, 1, 4},
						{3, 1, 1},
						{5, 2, 4}
					  },
		  			  {
						{0, 0, 3},
						{5, 2, 2},
						{5, 5, 5}
					  },
		 			  {
		 			  	{4, 0, 1},
					  	{3, 3, 0},
					  	{0, 5, 1}
					   	
					  },
					  {
					  	{0, 0, 0},
					   	{5, 4, 4},
					   	{4, 2, 2}
					  },
					  {
					  	{2, 2, 1},
					  	{4, 5, 1},
					  	{3, 3, 3}
					  }
					};
//tells about the correct position of the given color in solved cube taking all colors of the block as an argument.
vector<int> findex(vector<int> c){
	vector<int> res;
	res.push_back(c[0]);
	int ind[][3]={
				{8, 1, 5},
				{4, 0, 2},
				{7, 3, 6}
			};
	int i=1,j=1;// used to determine index for ind from the colors given.
	if(c[0]!=0 && c[0]!=5)//non-z base
 	{
 		int tmp=0;
 		int a1=-1,a2=-1;// stores the rest colors on the block which further are used to give the index
 		for(int k=1;k<c.size();k++){
 			if(axis[c[k]]%3==0)
 				a1=c[k];
 			else
 				a2=c[k];
		 }
		 if(a1!=-1)//for 1 block color a1,a2 both will be negetive
		 {
		 tmp=-1*(axis[a1]/abs(axis[a1]));
		 i=i+tmp;
		}
		tmp=0;
		if(a2!=-1){
				tmp=c[0]%2==0?-1*(axis[a2]/abs(axis[a2])):axis[a2]/abs(axis[a2]);
		 		j=j+tmp;
		}
		 
 	}
 	else{
 		int tmp=0;
 		int a1=-1,a2=-1;// stores the rest colors on the block which further are used to give the index
 		for(int k=1;k<c.size();k++){
 			if(axis[c[k]]%2==0)
 				a1=c[k];
 			else
 				a2=c[k];
		 }
		 if(a1!=-1)
		 {
		 tmp=(axis[a1]/abs(axis[a1]));
		 j=j+tmp;
		}
		tmp=0;
		if(a2!=-1){
				tmp=c[0]%2==0?-1*(axis[a2]/abs(axis[a2])):axis[a2]/abs(axis[a2]);
		 		i=i+tmp;
		}
	 }
	 
 	res.push_back(ind[i][j]);
 	return res;
			
}
//returns coordinates of a block
vector<int> blockindex(int i,int j, int k){
 	vector<int> res(3);
 	int tmp[]={1,0,-1};
 	if(i!=0 && i!=5)//non-z base
 	{
 		res[abs(axis[i])-1]=(axis[i])/abs(axis[i]);
 		res[2]=tmp[j];
 		res[(abs(axis[i]))%2]= i%2==0?tmp[k]:-1*tmp[k];	
	}
	else{
	    if(i==0){
	        res[2]=-1;
	    }
	    else{
	        res[2]=1;
	    }
	    res[0]=i%2==0?tmp[j]:-1*tmp[j];
	    res[1]=-1*tmp[k];
	}
	return res;
 }
 //returns facing of color, taking color as an argument from the cube
vector<int> face(int i){
	vector<int> res(3,0);
	if(i!=0 && i!=5)//non-z base
 	{
 		res[abs(axis[i])-1]=(axis[i])/abs(axis[i]);
 		
 	}
 	else if(i==0)
 		res[2]=-1;
 	else
 		res[2]=1;
return res;
}

vector<int> cross_product(vector<int> vect_A, vector<int> vect_B) 
  
{ 
    vector<int> cross_P(3,0);
    cross_P[0] = vect_A[1] * vect_B[2] - vect_A[2] * vect_B[1]; 
    cross_P[1] = vect_A[2] * vect_B[0] - vect_A[0] * vect_B[2]; 
    cross_P[2] = vect_A[0] * vect_B[1] - vect_A[1] * vect_B[0]; 
    
    return cross_P;
}

vector<int> dot_product(vector<int> vect_A, vector<int> vect_B) 
  
{ 
    vector<int> dot_P(3,0);

    dot_P[0] = vect_A[0] * vect_B[0];
    dot_P[1] = vect_A[1] * vect_B[1];
    dot_P[2] = vect_A[2] * vect_B[2]; 
    
    return dot_P;
    // return
}

vector<int> addvector(vector<int> A,vector<int> B){
    vector<int> res(3,0);
    for(int i=0;i<3;i++){
        res[i]=A[i]+B[i];
    }
    return res;
}
vector<int> negvector(vector<int> A){
    vector<int> res(3,0);
    for(int i=0;i<3;i++){
        res[i]=-1*A[i];
    }
    return res;
}

bool equalvector(vector<int> A,vector<int> B){
    
    for(int i=0;i<3;i++){
        if(A[i]!=B[i])
            return false;
    }
    return true;
}

void reverseColumns(int i) 
{ 
    for (int l = 0; l < 3; l++) 
        for (int j = 0, k = 2; 
             j < k; j++, k--) 
            swap( 
                cube[i][j][l], cube[i][k][l]);
} 
  
// Function for do transpose of matrix 
void transpose(int i) 
{ 
    for (int j = 0; j < 3; j++) 
        for (int k = j; k < 3; k++) 
            swap(cube[i][j][k], cube[i][k][j]); 
}


void reverse_row(int i){
	for(int j=0;j<3;j++){
		for(int k=0, l=2;k<l;k++,l--){
			swap(cube[i][j][k],cube[i][j][l]);
		}
	}
	
} 
//color of required facing 
int rot_res(vector<int> facing){
    for(int i=0;i<6;i++){
        if(equalvector(face(cube[i][1][1]),facing))
            return i;
    }
}
//to modify the cube matrix during rotation
//only side blocks
void rotate_side(vector<int> taxis,int color){
    int a;
    int temp[6][3];//to store result before modifying in cube
    vector<int> zero={0,0,0};
    for(int i=0;i<6;i++){
        vector<int> axis2=face(cube[i][1][1]);
        // same axis color do not get affected
        if(!equalvector(cross_product(axis2,taxis),zero)){
            int i1=rot_res(cross_product(axis2,taxis));// result color to which the current color(i) will go
            //for z axis rotation
            //only i get affected during z rotation
            if(taxis[2]!=0){
                if(color==5)
                    a=0;//a is the fix parameter
                if(color==0)
                    a=2;
                for(int k=0;k<3;k++){
                    temp[i1][k]=cube[i][a][k];
                }
            }
            //for y axis rotation
            // problems only with orange color
            //fix parameter is 2(for other color)
            else if(taxis[1]!=0){
                for(int k=0;k<3;k++){
                    if(color==2){
                        if(i==4 ){
                            temp[i1][k]=cube[i][2-k][0];
                        }
                        else if(i1==4){
                            temp[i1][k]=cube[i][2-k][2];
                        }
                        else{
                            temp[i1][k]=cube[i][k][2];
                        }
                    }
                    else{
                        if(i==4 ){
                            temp[i1][k]=cube[i][2-k][2];
                        }
                        else if(i1==4){
                            temp[i1][k]=cube[i][2-k][0];
                        }
                        else{
                            temp[i1][k]=cube[i][k][0];
                        }
                    }
                }
                
                
            }
            //for x axis rotation
            //if both(i and i1)belong to odd or even -> column changes to row ordering remains same
            //else ordering changes only
            else{
                //if both are of same category
                if((i1+i)%2==0){
                    
                        for(int k=0;k<3;k++){
                            if(abs(axis[i])%3==0){
                                if(color==1)
                                    temp[i1][k]=cube[i][2*(i%2)][2-k];
                                
                                else
                                    temp[i1][k]=cube[i][2*((i+1)%2)][2-k];
                            }
                            else{
                                if(color==1)
                                    temp[i1][k]=cube[i][2-k][2*(i%2)];
                                else
                                    temp[i1][k]=cube[i][2-k][2*((i+1)%2)];
                            }
                        }
                }
                //different category
                else{
                    for(int k=0;k<3;k++){
                            if(abs(axis[i])%3==0){
                                if(color==1)
                                    temp[i1][k]=cube[i][2*(i%2)][k];
                                
                                else
                                    temp[i1][k]=cube[i][2*((i+1)%2)][k];
                            }
                            else{
                                if(color==1)
                                    temp[i1][k]=cube[i][k][2*(i%2)];
                                else
                                    temp[i1][k]=cube[i][k][2*((i+1)%2)];
                            }
                        }
                }
                

            }
        }
        
    }
    //modifying cube according to cube
     if(taxis[2]!=0){
    for(int i1=1;i1<=4;i1++){
        for(int j=0;j<3;j++){
            cube[i1][a][j]=temp[i1][j];
        }
    }
     }
    else if(taxis[0]!=0){
        for(int i=0;i<6;i++){
            if(i==1 ||i==4)
                continue;
            for(int k=0;k<3;k++){
                if(abs(axis[i])%3==0){
                    if(color==1)
                        cube[i][2*(i%2)][k]=temp[i][k];
                    
                    else
                        cube[i][2*((i+1)%2)][k]=temp[i][k];
                }
                else{
                    if(color==1)
                        cube[i][k][2*(i%2)]=temp[i][k];
                    else
                        cube[i][k][2*((i+1)%2)]=temp[i][k];
                }
            }
                   
            
        
    }
}

    else {
        for(int i=0;i<6;i++){
            if(i==2 ||i==3)
                continue;
            for(int k=0;k<3;k++){
                if(color==2){
                    if(i==4){
                        cube[i][k][0]=temp[i][k];
                    }
                    else{
                        cube[i][k][2]=temp[i][k];
                    }
                }
                else{
                    if(i==4){
                        cube[i][k][2]=temp[i][k];
                    }
                    else{
                        cube[i][k][0]=temp[i][k];
                    }
                }
            }
                  
    }
}
}

void clockwise(int color){
    vector<int> axis=face(color);
    int i,j;
    int temp=-1;
    vector<int> ax(3,0);
    for(int a=0;a<3;a++){
        ax[a]=abs(axis[a]);
    }
    for(i=0;i<6;i++){
        for(j=0;j<9;j++){
   if ( equalvector(dot_product(fmat[i][j].v1,ax),axis)){
       if(j==0)
        {
            temp=i;
        }
       fmat[i][j].v1=addvector(cross_product(fmat[i][j].v1,axis), dot_product(fmat[i][j].v1,ax));// changes to v1 vector in face matrix
       fmat[i][j].v2=addvector(cross_product(fmat[i][j].v2,axis), dot_product(fmat[i][j].v2,ax));// changes to v2 vector in face matrix

   }   
}

}
//modifying face
  transpose(temp);
  reverse_row(temp);
  //modify side
  rotate_side(axis,color);
}


void anti_clockwise( int color){
    vector<int> taxis=face(color);
    vector<int> neg(3,0);
    for(int a=0;a<3;a++){
        neg[a]=-1*taxis[a];
    }
    vector<int> ax(3,0);
    for(int a=0;a<3;a++){
        ax[a]=abs(taxis[a]);
    }
    int temp=-1;
    int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<9;j++){
            if ( equalvector(dot_product(fmat[i][j].v1,ax),taxis)){
                if(j==0)
                    temp=i;
                
              if(axis[color]<0){
                  
                fmat[i][j].v1=addvector(cross_product(fmat[i][j].v1,neg), dot_product(fmat[i][j].v1,neg));
                fmat[i][j].v2=addvector(cross_product(fmat[i][j].v2,neg), dot_product(fmat[i][j].v2,neg));
              }
              else{
                  fmat[i][j].v1=addvector(cross_product(fmat[i][j].v1,neg), dot_product(fmat[i][j].v1,taxis));
                  fmat[i][j].v2=addvector(cross_product(fmat[i][j].v2,neg), dot_product(fmat[i][j].v2,taxis));
              }
                  
              }
            
            
    }

    }
    transpose(temp); 
    reverseColumns(temp);
    rotate_side(neg,color);
    
}


void printcube(){
    	
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
			    cout<<cube[i][j][k]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
}


int rot(vector<int> intial,vector<int> final,int axis_rot){
    if(equalvector(intial,final))
        return -1;
    vector<int> temp=cross_product(intial,final);
    
    vector<int> face_axis=face(axis_rot);
    if(equalvector(face_axis,temp)){
        return (axis_rot+6);
    }
    else
        return (axis_rot);
}

vector< int > other_color_info(int p , int k){
    vector< int > res;
    for(int i=0;i<6;i++){
        if(i==p)
            continue;
        for(int j=0;j<8;j++){
            if(equalvector(fmat[i][j].v1,fmat[p][k].v1))
            {
                res.push_back(i);
            }
        }
    }
    return res;
}
int solved_color=0;

void reverse_moves(vector<int> rt){
    int n=rt.size();
    for(int i=n-1;i>=0;i--){
        if(rt[i]>=6){
            clockwise(rt[i]-6);
        }
        else
            anti_clockwise(rt[i]);
    }
}

int leader_color;

string location(int i,int scolor){
    vector< vector<int> > temp={
        {1,0},{0,1},{-1,0},{0,-1}
    };
    vector<int> curr_pos=fmat[0][i].v1;
    curr_pos.pop_back();
    vector<int> leader_loc;
    if(leader_color==1 || leader_color==2)
        leader_loc=fmat[0][leader_color].v1;
    else if(leader_color==4)
        leader_loc=fmat[0][3].v1;
    else
        leader_loc=fmat[0][4].v1;
    leader_loc.pop_back();
    int l_ind,final_ind,c_ind;
    for( int j=0;j<4;j++){
        if(temp[j][0]==leader_loc[0] && temp[j][1]==leader_loc[1])
        l_ind=j;    
    }
    for(int j=0;j<4;j++){
        if(temp[j][0]==curr_pos[0] && temp[j][1]==curr_pos[1])
        c_ind=j;    
    }
    if(equalvector(cross_product(face(leader_color),face(scolor)),{0,0,1}))
        final_ind=(l_ind+1)%4;
    else if(equalvector(cross_product(face(leader_color),face(scolor)),{0,0,-1}))
    {
        if(l_ind==0)
            final_ind=3;
        else
            final_ind=(l_ind-1);
    }
    else
        final_ind=(l_ind+2)%4;
        
    //----------//
    if(final_ind==c_ind)
        return "up";
    else if((final_ind+1)%4 == c_ind)
        return "left";
    else if((c_ind+1)%4 == final_ind)
        return "right";
    else
        return "down";
    
    
}
string location_q1(int i,int scolor,int facing_color){
    vector< vector<int> > temp={
        {1,0},{0,1},{-1,0},{0,-1}
    };
    vector<int> curr_pos=fmat[0][i].v1;
    curr_pos.pop_back();
    vector<int> leader_loc;
    if(leader_color==1 || leader_color==2)
        leader_loc=fmat[0][leader_color].v1;
    else if(leader_color==4)
        leader_loc=fmat[0][3].v1;
    else
        leader_loc=fmat[0][4].v1;
    leader_loc.pop_back();
    int l_ind,final_ind,c_ind;
    for( int j=0;j<4;j++){
        if(temp[j][0]==leader_loc[0] && temp[j][1]==leader_loc[1])
        l_ind=j;    
    }
    if(facing_color==1 || facing_color==2){
        c_ind=facing_color-1;
    }
    else if(facing_color==3)
        c_ind=3;
    else
        c_ind=2;
    if(equalvector(cross_product(face(leader_color),face(scolor)),{0,0,1}))
        final_ind=(l_ind+1)%4;
    else if(equalvector(cross_product(face(leader_color),face(scolor)),{0,0,-1}))
    {
        if(l_ind==0)
            final_ind=3;
        else
            final_ind=(l_ind-1);
    }
    else
        final_ind=(l_ind+2)%4;
    
    //----------//
    if(final_ind==c_ind)
        return "up";
    else if((final_ind+1)%4 == c_ind)
        return "left";
    else if((c_ind+1)%4 == final_ind)
        return "right";
    else
        return "down";
    
    
}

void cross(int i,vector<int> &temp_ans){
    vector<int> q1,q2;
    vector<int> pos=fmat[0][i].v1;
    vector<int> facing=fmat[0][i].v2;
    vector< int > other_color=other_color_info(0,i);
    int scolor=other_color[0];
    vector<int> sfacing=fmat[scolor][3].v2;
    if(pos[2]==1){
        if(equalvector(facing,{0,0,1})){
            if(solved_color==0){
                clockwise(rot_res(sfacing));
                clockwise(rot_res(sfacing));
                temp_ans.push_back(rot_res(sfacing));
                temp_ans.push_back(rot_res(sfacing));
            }
            else{
                string loc=location(i,scolor);
                
                 if(loc=="left"){
                    clockwise(5);
                    temp_ans.push_back(5);
                    int t=rot_res(fmat[scolor][3].v2);
                    clockwise(t);
                    clockwise(t);
                    temp_ans.push_back(t);
                    temp_ans.push_back(t);
                }
                else if(loc=="right"){
                    anti_clockwise(5);
                    temp_ans.push_back(11);
                    int t=rot_res(fmat[scolor][3].v2);
                    clockwise(t);
                    clockwise(t);
                    temp_ans.push_back(t);
                    temp_ans.push_back(t);
                }
                else if(loc=="down"){
                    clockwise(5);
                    clockwise(5);
                    temp_ans.push_back(5);
                    temp_ans.push_back(5);
                    int t=rot_res(fmat[scolor][3].v2);
                    clockwise(t);
                    clockwise(t);
                    temp_ans.push_back(t);
                    temp_ans.push_back(t);
                }
                else{
                    int t=rot_res(fmat[scolor][3].v2);
                    clockwise(t);
                    clockwise(t);
                    temp_ans.push_back(t);
                    temp_ans.push_back(t);
                }
            }
        }
        else{
            if(solved_color==0){
                int axis_rot=rot_res(facing);
                clockwise(axis_rot);
                temp_ans.push_back(axis_rot);
                int t=rot_res(fmat[scolor][3].v2);
                anti_clockwise(t);
                temp_ans.push_back(t+6);
            }
            else{
                string loc=location(i,scolor);
                
                if(loc=="left"){
                    anti_clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing)+6);
                    int t=rot_res(fmat[scolor][3].v2);
                    clockwise(t);
                    temp_ans.push_back(t);
                    clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing));
                }
                else if(loc=="right"){
                    clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing));
                    int t=rot_res(fmat[scolor][3].v2);
                    anti_clockwise(t);
                    temp_ans.push_back(t+6);
                    anti_clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing)+6);
                }
                else if(loc=="down"){
                    anti_clockwise(0);
                    temp_ans.push_back(6);
                    clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing));
                    int t=rot_res(fmat[scolor][3].v2);
                    anti_clockwise(t);
                    temp_ans.push_back(t+6);
                    anti_clockwise(rot_res(facing));
                     temp_ans.push_back(rot_res(facing)+6);
                }
                else{
                    clockwise(0);
                     temp_ans.push_back(0);
                    clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing));
                    int t=rot_res(fmat[scolor][3].v2);
                    anti_clockwise(t);
                    temp_ans.push_back(t+6);
                    anti_clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing)+6);
                }
            }
        }
    }
    else if(pos[2]==-1){
        if(equalvector(facing,{0,0,-1}))
        {
            if(solved_color==0)
                return;
            else{
                string loc=location(i,scolor);
                if(loc=="left"){
                    anti_clockwise(rot_res(sfacing));
                    temp_ans.push_back(rot_res(sfacing)+6);
                    clockwise(0);
                    temp_ans.push_back(0);
                    clockwise(rot_res(sfacing));
                    temp_ans.push_back(rot_res(sfacing));
                }
                else if(loc=="right"){
                    anti_clockwise(rot_res(sfacing));
                    temp_ans.push_back(rot_res(sfacing)+6);
                    anti_clockwise(0);
                    temp_ans.push_back(6);
                    clockwise(rot_res(sfacing));
                    temp_ans.push_back(rot_res(sfacing));
                }
                else if(loc=="down"){
                    anti_clockwise(rot_res(sfacing));
                    temp_ans.push_back(rot_res(sfacing)+6);
                    clockwise(0);
                    clockwise(0);
                    temp_ans.push_back(0);
                    temp_ans.push_back(0);
                    clockwise(rot_res(sfacing));
                    temp_ans.push_back(rot_res(sfacing));
                }
                else{
                    return;
                }
            }
        }
        else{
            if(solved_color==0){
                anti_clockwise(rot_res(facing));
                temp_ans.push_back(rot_res(facing)+6);
                int t=rot_res(fmat[scolor][3].v2);
                anti_clockwise(t);
                temp_ans.push_back(t+6);
            }
            else{
                string loc=location(i,scolor);
                
                if(loc=="left"){
                    clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing));
                    int t=rot_res(fmat[scolor][3].v2);
                    clockwise(t);
                    temp_ans.push_back(t);
                }
                else if(loc=="right"){
                    anti_clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing)+6);
                    int t=rot_res(fmat[scolor][3].v2);
                    anti_clockwise(t);
                    temp_ans.push_back(t+6);
                }
                else if(loc=="down"){
                    anti_clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing)+6);
                    anti_clockwise(0);
                    temp_ans.push_back(6);
                    int t=rot_res(fmat[scolor][3].v2);
                    anti_clockwise(t);
                    temp_ans.push_back(t+6);
                }
                else{
                    clockwise(rot_res(facing));
                    temp_ans.push_back(rot_res(facing));
                    anti_clockwise(0);
                    temp_ans.push_back(6);
                    int t=rot_res(fmat[scolor][3].v2);
                    clockwise(t);
                    temp_ans.push_back(t);
                }
            }
        }
    }
    else{
         int a=rot_res(facing);
            int b;
            if(a==1 || a==4)
                b=1;
            else
                b=0;  
        if(solved_color==0){
            if(pos[b]==-1*(a%2!=0?1:-1)){
                clockwise(rot_res(sfacing));
                temp_ans.push_back(rot_res(sfacing));
            }
            else
            {
                anti_clockwise(rot_res(sfacing));
                temp_ans.push_back(rot_res(sfacing)+6);
            }
        }
        else{
            
            string loc=location_q1(i,scolor,a);
            if((loc=="right" && pos[b]==-1*(a%2!=0?1:-1)) ||(loc=="left" && pos[b]==1*(a%2!=0?1:-1)) ){
                clockwise(0);
                clockwise(0);
                temp_ans.push_back(0);
                temp_ans.push_back(0);
            }
            else if(loc=="up"){
                if(pos[b]==-1*(a%2!=0?1:-1)){
                    anti_clockwise(0);
                    temp_ans.push_back(6);
                }
                else{
                    clockwise(0);
                    temp_ans.push_back(0);
                }
            }
            else if(loc=="down"){
                if(pos[b]==1*(a%2!=0?1:-1)){
                    anti_clockwise(0);
                    temp_ans.push_back(6);
                }
                else{
                    clockwise(0);
                    temp_ans.push_back(0);
                }
            }
            if(pos[b]==-1*(a%2!=0?1:-1)){
                clockwise(rot_res(sfacing));
                temp_ans.push_back(rot_res(sfacing));
            }
            else{
                anti_clockwise(rot_res(sfacing));
                temp_ans.push_back(rot_res(sfacing)+6);
            }
        }
            
    }
}

void step1(){
    vector<int> answer;
    int answer_length=15;
    int i,j,k,l;
    for(int i=1;i<5;i++){
        if(i==1||i==2)
            leader_color=i;
        else if(i==3)
            leader_color=4;
        else
            leader_color=3;
        for(int j=1;j<5;j++){
            for(int k=1;k<5;k++){
                for(int l=1;l<5;l++){
                    if(!(i==j || i==k||i==l||j==k||j==l||k==l)){
                        vector<int> temp_answer;
                        solved_color=0;
                        cross(i,temp_answer);
                        solved_color++;
                        cross(j,temp_answer);
                        solved_color++;
                        cross(k,temp_answer);
                        solved_color++;
                        cross(l,temp_answer);
                        solved_color++;
                        
                        vector< int > other_color=other_color_info(0,leader_color);
                        int scolor=other_color[0];
                        vector<int> sfacing;
                        while(true){
                                
                            sfacing=fmat[scolor][3].v2;
                            
                            vector<int> final=face(scolor);
                            int rt=rot(sfacing,final,0);
                            // cout<<rt<<" ";
                            if(rt>=6)
                                anti_clockwise(rt-6);
                            else if(rt<6 && rt>=0)
                                clockwise(rt);
                            else
                                break;
                            temp_answer.push_back(rt);
                        }
                        if(answer_length>temp_answer.size()){
                            answer_length=temp_answer.size();
                            answer=temp_answer;
                        }
                        reverse_moves(temp_answer);
                        
                    }
                }
            }
        }
    }
    for(auto x: answer){
        if(x>=6)
            anti_clockwise(x-6);
        else
            clockwise(x);
        cout<<x<<" ";
    }
}

void corner(int i,vector<int> &temp_ans){
    vector<int> pos=fmat[0][i].v1;
    vector<int> facing=fmat[0][i].v2;
    
    vector< int > other_color=other_color_info(0,i);
    other_color.push_back(0);
    int scolor;
    vector<int> f_ind,sfacing;
    
    
    
    for(auto x:other_color){
        
        f_ind=findex(other_color);
        if(!equalvector(fmat[f_ind[0]][f_ind[1]].v2,{0,0,1}))
            break;
        else
            swap(other_color[0],other_color[1]);
    }
    
    
        
    scolor=f_ind[0];
    sfacing=fmat[f_ind[0]][f_ind[1]].v2;
    if(pos[2]==1 && !equalvector(facing,{0,0,1})){
        if(!equalvector(sfacing,face(scolor))){
            if(equalvector(cross_product(sfacing,face(scolor)),{0,0,-1})){
                clockwise(5);
                temp_ans.push_back(5);
            }
            else if(equalvector(cross_product(sfacing,face(scolor)),{0,0,1})){
                anti_clockwise(5);
                temp_ans.push_back(11);
            }
            else{
                clockwise(5);
                temp_ans.push_back(5);
                clockwise(5);
                temp_ans.push_back(5);
            }
        }
        
        if(equalvector(cross_product(fmat[0][i].v2,fmat[f_ind[0]][f_ind[1]].v2),{0,0,-1})){
            
            int t=rot_res(fmat[0][i].v2);
            clockwise(t);
            temp_ans.push_back(t);
            clockwise(5);
            temp_ans.push_back(5);
            anti_clockwise(t);
            temp_ans.push_back(t+6);
        }
        else{
            
            int t=rot_res(fmat[0][i].v2);
            anti_clockwise(t);
            temp_ans.push_back(t+6);
            anti_clockwise(5);
            temp_ans.push_back(11);
            clockwise(t);
            temp_ans.push_back(t);
        }
       
    }
    
        
    
    
}

void corner_check(int i,vector<int> &temp_ans){
    vector<int> pos=fmat[0][i].v1;
        vector<int> facing=fmat[0][i].v2;
        
        vector< int > other_color=other_color_info(0,i);
        vector<int> other=other_color;
        other.push_back(0);
        vector<int> t_ind=findex(other);
        vector<int> right_pos(3,0);
        for(auto x:other_color)
            right_pos=addvector(face(x),right_pos);
        right_pos=addvector({0,0,1},right_pos);
        vector<int> temp_ri=right_pos;
        temp_ri[2];
            
        if(pos[2]==-1 && !equalvector(facing,{0,0,-1})){
            
            int t=rot_res(facing);
            if(t==1 ||t==4){
                if(pos[1]*pos[0]==1){
                    anti_clockwise(t);
                    temp_ans.push_back(t+6);
                    anti_clockwise(5);
                    clockwise(t);
                    temp_ans.push_back(11);
                    temp_ans.push_back(t);
                }
                else{
                    clockwise(t);
                    temp_ans.push_back(t);
                    clockwise(5);
                    anti_clockwise(t);
                    temp_ans.push_back(5);
                    temp_ans.push_back(t+6);
                }
            }
            else{
                if(pos[1]*pos[0]!=1){
                    anti_clockwise(t);
                    temp_ans.push_back(t+6);
                    anti_clockwise(5);
                    clockwise(t);
                    temp_ans.push_back(11);
                    temp_ans.push_back(t);
                }
                else{
                    clockwise(t);
                    temp_ans.push_back(t);
                    clockwise(5);
                    anti_clockwise(t);
                    temp_ans.push_back(5);
                    temp_ans.push_back(t+6);
                }
            }
            
        }
        else if(pos[2]==-1 && !equalvector(pos,temp_ri)){
            if(equalvector(fmat[t_ind[0]][t_ind[1]].v2,face(t_ind[0])))
                return;
            int t,p;
            if(equalvector(pos,{1,1,-1})){
                t=2;
            }
            else if(equalvector(pos,{-1,1,-1})){
                t=4;
            }
            else if(equalvector(pos,{-1,-1,-1})){
                t=3;
            }
            else{
                t=1;
            }
            clockwise(t);
            temp_ans.push_back(t);
            clockwise(5);
            temp_ans.push_back(5);
            anti_clockwise(t);
            temp_ans.push_back(t+6);
        }
        else if(pos[2]==1 && equalvector(facing,{0,0,1})){
        int count=0;
        
        while(true){
            if(equalvector(pos,right_pos))
                break;
            clockwise(5);
            pos=fmat[0][i].v1;
            count++;
        }
        if(count==3){
            temp_ans.push_back(11);
        }
        else if(count==1)
            temp_ans.push_back(5);
        else if(count==2){
            temp_ans.push_back(5);
            temp_ans.push_back(5);
        }
            
            
            if(pos[0]==1 ){
                if(pos[1]==1){
                    clockwise(2);
                    temp_ans.push_back(2);
                    anti_clockwise(5);
                    temp_ans.push_back(11);
                    anti_clockwise(2);
                    temp_ans.push_back(8);
                }
                else{
                    anti_clockwise(3);
                    temp_ans.push_back(9);
                    clockwise(5);
                    temp_ans.push_back(5);
                    clockwise(3);
                    temp_ans.push_back(3);
                }
            }
            else{
                if(pos[1]==1){
                    anti_clockwise(2);
                    temp_ans.push_back(8);
                    clockwise(5);
                    temp_ans.push_back(5);
                    clockwise(2);
                    temp_ans.push_back(2);
                }
                else{
                    clockwise(3);
                    temp_ans.push_back(3);
                    anti_clockwise(5);
                    temp_ans.push_back(11);
                    anti_clockwise(3);
                    temp_ans.push_back(9);
                }
            }
        }
        
}

void step2(){
    vector<int> answer;
    int answer_length=35;
    int i,j,k,l;
    for(int i=5;i<9;i++){
        for(int j=5;j<9;j++){
            for(int k=5;k<9;k++){
                for(int l=5;l<9;l++){
                    if(!(i==j || i==k||i==l||j==k||j==l||k==l)){
                        vector<int> temp_answer;
                        corner_check(i,temp_answer);
                        corner(i,temp_answer);
                        corner_check(j,temp_answer);
                        corner(j,temp_answer);
                        corner_check(k,temp_answer);
                        corner(k,temp_answer);
                        corner_check(l,temp_answer);
                        corner(l,temp_answer);
                        // cout<<"for pair ("<<i<<j<<k<<l<<")"<<"\n";
                        // cout<<temp_answer.size()<<" ";
                        // for(auto x:temp_answer)
                        //     cout<<x<<" ";
                        // cout<<"\n";
                        if(answer_length>temp_answer.size()){
                            answer_length=temp_answer.size();
                            answer=temp_answer;
                        }
                        reverse_moves(temp_answer);
                        
                    }
                }
            }
        }
    }
    cout<<answer.size()<<"\n";
    for(auto x: answer){
        
        if(x>=6)
            anti_clockwise(x-6);
        else
            clockwise(x);
        cout<<x<<" ";
    }
}

void middle(int i,vector<int> &temp_ans){
    
    vector<int> pos=fmat[i][2].v1;
    vector<int> facing=fmat[i][2].v2;
    
    vector< int > other_color=other_color_info(i,2);
    other_color.push_back(i);
    vector<int> sfacing,f_ind,w_ind;
    f_ind=findex(other_color);
    
    int scolor,fcolor;
    
    if(equalvector(fmat[f_ind[0]][f_ind[1]].v2,{0,0,1}))
    {
        swap(other_color[0],other_color[1]);
        f_ind=findex(other_color);
        
    }
    scolor=other_color[0];
    fcolor=other_color[1];
    
    sfacing=fmat[f_ind[0]][f_ind[1]].v2;
    vector<int> right_pos(3,0);
    for(auto x:other_color)
        right_pos=addvector(face(x),right_pos);
    
    if(equalvector(pos,right_pos) && equalvector(fmat[f_ind[0]][f_ind[1]].v2,face(f_ind[0]))){
        return;
    }
        
    
    if(pos[2]==1){
        vector<int> final=negvector(face(fcolor));
         while(true){
                                
            sfacing=fmat[f_ind[0]][f_ind[1]].v2;
            int rt=rot(sfacing,final,5);
            // cout<<rt<<" ";
            if(rt>=6)
                anti_clockwise(rt-6);
            else if(rt<6 && rt>=0)
                clockwise(rt);
            else
                break;
            temp_ans.push_back(rt);
        }
        other_color.push_back(0);
        swap(other_color[0],other_color[2]);
        w_ind=findex(other_color);
        
        if(axis[fcolor]/abs(axis[fcolor])==1*(scolor%2!=0?1:-1)){
            clockwise(fcolor);
            temp_ans.push_back(fcolor);
            clockwise(5);
            temp_ans.push_back(5);
            anti_clockwise(fcolor);
            temp_ans.push_back(fcolor+6);
            corner(w_ind[1],temp_ans);
        }
        else{
            anti_clockwise(fcolor);
            temp_ans.push_back(fcolor+6);
            clockwise(5);
            temp_ans.push_back(5);
            clockwise(fcolor);
            temp_ans.push_back(fcolor);
            
            clockwise(5);
            temp_ans.push_back(5);
            clockwise(scolor);
            temp_ans.push_back(scolor);
            anti_clockwise(5);
            temp_ans.push_back(11);
            anti_clockwise(scolor);
            temp_ans.push_back(scolor+6);
        }
        
    }
    else if(equalvector(pos,right_pos) && !equalvector(fmat[f_ind[0]][f_ind[1]].v2,face(f_ind[0]))){
            int t,p;
            if(equalvector(pos,{1,1,0})){
                t=2;
                p=1;
            }
            else if(equalvector(pos,{-1,1,0})){
                t=4;
                p=2;
            }
            else if(equalvector(pos,{-1,-1,0})){
                t=3;
                p=4;
            }
            else{
                t=1;
                p=3;
            }
                
            clockwise(t);
            temp_ans.push_back(t);
            clockwise(5);
            temp_ans.push_back(5);
            clockwise(5);
            temp_ans.push_back(5);
            anti_clockwise(t);
            temp_ans.push_back(t+6);
            clockwise(5);
            temp_ans.push_back(5);
            clockwise(t);
            temp_ans.push_back(t);
            anti_clockwise(5);
            temp_ans.push_back(11);
            anti_clockwise(5);
            temp_ans.push_back(11);
            anti_clockwise(t);
            temp_ans.push_back(t+6);
            clockwise(5);
            temp_ans.push_back(5);
            anti_clockwise(p);
            temp_ans.push_back(p+6);
            anti_clockwise(5);
            temp_ans.push_back(11);
            clockwise(p);
            temp_ans.push_back(p);
        
    }
    else{
        int t,p;
        if(equalvector(pos,{1,1,0})){
            t=2;
            p=1;
        }
        else if(equalvector(pos,{-1,1,0})){
            t=4;
            p=2;
        }
        else if(equalvector(pos,{-1,-1,0})){
            t=3;
            p=4;
        }
        else{
            t=1;
            p=3;
        }
            
        clockwise(t);
        temp_ans.push_back(t);
        anti_clockwise(5);
        temp_ans.push_back(11);
        anti_clockwise(t);
        temp_ans.push_back(t+6);
        anti_clockwise(5);
        temp_ans.push_back(11);
        anti_clockwise(p);
        temp_ans.push_back(p+6);
        clockwise(5);
        temp_ans.push_back(5);
        clockwise(p);
        temp_ans.push_back(p);
        
        middle(i,temp_ans);
    }

}

void step3(){
    vector<int> answer;
    // middle(3,answer);
    int answer_length=50;
    int i,j,k,l;
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            for(int k=1;k<5;k++){
                for(int l=1;l<5;l++){
                    if(!(i==j || i==k||i==l||j==k||j==l||k==l)){
                        vector<int> temp_answer;
                        middle(i,temp_answer);
                        middle(j,temp_answer);
                        middle(k,temp_answer);
                        middle(l,temp_answer);
                        // cout<<"for pair ("<<i<<j<<k<<l<<")"<<"\n";
                        // cout<<temp_answer.size()<<"\n";
                        // for(auto x:temp_answer)
                        //     cout<<x<<" ";
                        // cout<<"\n";
                        if(answer_length>temp_answer.size()){
                            answer_length=temp_answer.size();
                            answer=temp_answer;
                        }
                        reverse_moves(temp_answer);
                        
                    }
                }
            }
        }
    }
    cout<<answer.size()<<"\n";
   for(auto x: answer){
        if(x>=6)
            anti_clockwise(x-6);
        else
            clockwise(x);
        cout<<x<<" ";
    }
}

void oll_corner(vector <int> &temp_ans){
    int count=0;
    for(int i=0;i<3;i=i+2){
        for(int j=0;j<3;j=j+2){
                if(cube[5][i][j]==5)   
                count++;
                // cout<<"\n"<<cube[5][i][j]<<" ";
        } }
        // cout<<"count="<<count<<"\n";
    if(count==0){
        while(true){
            if(cube[1][0][0]==5 && cube[1][0][2]==5)
            break;
            clockwise(5);temp_ans.push_back(5);
        }
        if(cube[4][0][0]==5 && cube[4][0][2]==5){
            clockwise(1);
            for(int i=0;i<3;i++){
                clockwise(2);clockwise(5);anti_clockwise(2);anti_clockwise(5);
                temp_ans.push_back(2);temp_ans.push_back(5);temp_ans.push_back(8);temp_ans.push_back(11);
            }
            anti_clockwise(1);temp_ans.push_back(7);
        }
        else{
            // cout<<"different side\n";
            clockwise(5);temp_ans.push_back(5);
            clockwise(2);clockwise(5);clockwise(5);clockwise(2);clockwise(2);anti_clockwise(5);
            temp_ans.push_back(2);temp_ans.push_back(5);temp_ans.push_back(5);temp_ans.push_back(2);temp_ans.push_back(2);temp_ans.push_back(5+6);
            clockwise(2);clockwise(2);anti_clockwise(5);clockwise(2);clockwise(2);clockwise(5);clockwise(5);clockwise(2);
            temp_ans.push_back(2);temp_ans.push_back(2);temp_ans.push_back(6+5);temp_ans.push_back(5);temp_ans.push_back(5);temp_ans.push_back(2);
        }
    }
    else if(count==1){
        while(true){
            if(cube[5][2][0]==5 && cube[1][0][2]==5){
              clockwise(2);clockwise(5);anti_clockwise(2);clockwise(5);clockwise(2);
              temp_ans.push_back(2);temp_ans.push_back(5);temp_ans.push_back(2+6);temp_ans.push_back(5);temp_ans.push_back(2);
              clockwise(5);clockwise(5);anti_clockwise(2);
              temp_ans.push_back(5);temp_ans.push_back(5);temp_ans.push_back(2+6);
              break;
            }
            if(cube[5][2][2]==5 && cube[1][0][0]==5){
                anti_clockwise(3);anti_clockwise(5);clockwise(3);anti_clockwise(5);anti_clockwise(3);
                temp_ans.push_back(3+6);temp_ans.push_back(5+6);temp_ans.push_back(3);temp_ans.push_back(6+5);temp_ans.push_back(3+6);
                clockwise(5);clockwise(5);clockwise(3);
                temp_ans.push_back(5);temp_ans.push_back(5);temp_ans.push_back(3);
                break;
            }
            clockwise(5);
        }
    }
  
    else if(count==2){
        if((cube[5][0][0]==5 && cube[5][2][2]==5) || (cube[5][0][2]==5 && cube[5][2][0]==5) ){ //2 corners diagnally placed
        //   cout<<"diagnal\n";
            while(true){
                if(cube[1][0][0]==5 && cube[2][0][2]==5)
                    break;
                clockwise(5);   //r'urd'r'u'rd
            }
            anti_clockwise(2);clockwise(1);clockwise(2);anti_clockwise(4);
            temp_ans.push_back(2+6);temp_ans.push_back(1);temp_ans.push_back(2);temp_ans.push_back(4+6);
            anti_clockwise(2);anti_clockwise(1);clockwise(2);clockwise(4);
            temp_ans.push_back(2+6);temp_ans.push_back(1+6);temp_ans.push_back(2);temp_ans.push_back(4);
        }
        else{ // 2 corners placed in an adjacsent manner
            while(true){
                if(cube[5][2][0]==5 && cube[5][2][2]==5){
                break;}
                clockwise(5);
            }
            if(cube[4][0][0]==5 && cube[4][0][2]==5){
                clockwise(5);clockwise(5);
                clockwise(2);clockwise(2);clockwise(0);anti_clockwise(2);clockwise(5);clockwise(5);clockwise(2);
                temp_ans.push_back(2);temp_ans.push_back(2);temp_ans.push_back(0);temp_ans.push_back(2+6);temp_ans.push_back(5);temp_ans.push_back(5);temp_ans.push_back(2);
                anti_clockwise(0);anti_clockwise(2);clockwise(5);clockwise(5);anti_clockwise(2);
                temp_ans.push_back(6);temp_ans.push_back(2+6);temp_ans.push_back(5);temp_ans.push_back(5);temp_ans.push_back(8);
            }
            else{
                anti_clockwise(5);
                clockwise(3);clockwise(1);anti_clockwise(2);anti_clockwise(1);
                temp_ans.push_back(3);temp_ans.push_back(1);temp_ans.push_back(2+6);temp_ans.push_back(7);
                anti_clockwise(3);clockwise(1);clockwise(2);anti_clockwise(1);
                temp_ans.push_back(3+6);temp_ans.push_back(1);temp_ans.push_back(2);temp_ans.push_back(1+6);
            }
            cout<<"aa raha hai, tle mar jaa kahin jake\n";
        }
    }
    else{
        return;
    }
    
}
void step4(vector <int> &temp_ans){
    if((cube[5][0][1]==5 && cube[5][2][1]==5) && (cube[5][1][0]==5 && cube[5][1][2]==5)){ //yellow cross solved
        oll_corner(temp_ans);
    }
    else if((cube[5][0][1]==5 && cube[5][2][1]==5) || (cube[5][1][0]==5 && cube[5][1][2]==5)){ //if line is already formed
        int f; int r;
        // cout<<"line\n";
        if(cube[5][0][1]==5 && cube[5][2][1]==5){
            f=2;r=4;
        }
        else{
            f=1;r=2;
        }
        clockwise(f); temp_ans.push_back(f);  //frur'uf'
        clockwise(r); temp_ans.push_back(r);
        clockwise(5); temp_ans.push_back(5);
        anti_clockwise(r); temp_ans.push_back(r+6);
        anti_clockwise(5); temp_ans.push_back(5+6);
        anti_clockwise(f); temp_ans.push_back(f+6);
       
    }
    else if((cube[5][0][1]==5 && (cube[5][0][1]==5 || cube[5][1][2]==5)) || (cube[5][2][1]==5 && (cube[5][1][0]==5 || cube[5][1][2]==5 ))){ //L is already formed
        int b,l;
        // cout<<"l";
        if(cube[5][0][1]==5){
            if(cube[5][1][0]==5){
            b=1;l=2;}
            else if(cube[5][1][2]==5){
                b=3;l=1;
            }
        }
        else{
            if(cube[5][1][0]==5){
                b=2;l=4;
            }
             else if(cube[5][1][2]==5){
                b=4;l=3;
            }
            
        }
        clockwise(b);temp_ans.push_back(b);     //BULU'L'B'  //FURU'R'F'
        clockwise(5);temp_ans.push_back(5);
        clockwise(l);temp_ans.push_back(l);
        anti_clockwise(5);temp_ans.push_back(11);
        anti_clockwise(l);temp_ans.push_back(l);
        anti_clockwise(b);temp_ans.push_back(b);
    }
    else {  //no line and L is formed
        // cout<<"none\n";
        int f=1,r=2,b=4,l=3;
        clockwise(f); temp_ans.push_back(f);
        clockwise(r); temp_ans.push_back(r);
        clockwise(5); temp_ans.push_back(5);
        anti_clockwise(r); temp_ans.push_back(r+6);
        anti_clockwise(5); temp_ans.push_back(5+6);
        anti_clockwise(f); temp_ans.push_back(f+6);
        
        step4(temp_ans);
        
    }
    oll_corner(temp_ans);
}

void oll(){
    vector<int> answer;
    step4(answer);
    cout<<answer.size()<<"\n";
    for(auto x:answer)
        cout<<x<<" ";
}



void pll_part1(){
    vector<int> temp_ans;
    bool headlight=false;
    int i;
    for( i=1;i<5;i++){
        int map[5][1]={
           {0},{3},{1},{4},{2}
        };
        
        vector<int> face1=fmat[i][5].v2;
        vector<int> face2=fmat[i][8].v2;
        if(equalvector(face1,face2))
        {
          while(true){
                face1=fmat[i][5].v2;
                
                vector<int> final=face(map[i][0]);
                int rt=rot(face1,final,5);
                // cout<<rt<<" ";
                if(rt>=6)
                    anti_clockwise(rt-6);
                else if(rt<6 && rt>=0)
                    clockwise(rt);
                else
                    break;
                temp_ans.push_back(rt);
            }
            headlight=true;
            break;
        }
    }
    if(headlight){
        int f=i,r;
        if(i==1)
            r=2;
        else if(i==2)
            r=4;
        else if(i==3)
            r=1;
        else
            r=3;
            
        clockwise(r);       temp_ans.push_back(r);
        clockwise(5);       temp_ans.push_back(11);
        anti_clockwise(r);  temp_ans.push_back(r+6);
        anti_clockwise(5);  temp_ans.push_back(11);
        anti_clockwise(r);  temp_ans.push_back(r+6);
        clockwise(f);       temp_ans.push_back(f);
        clockwise(r);       temp_ans.push_back(r);
        clockwise(r);       temp_ans.push_back(r);
        anti_clockwise(5);  temp_ans.push_back(11);
        anti_clockwise(r);  temp_ans.push_back(r+6);
        anti_clockwise(5);  temp_ans.push_back(11);
        clockwise(r);       temp_ans.push_back(r);
        clockwise(5);       temp_ans.push_back(11);
        anti_clockwise(r);  temp_ans.push_back(r+6);
        anti_clockwise(f);  temp_ans.push_back(f+6);
    }
    else{
        clockwise(1);       temp_ans.push_back(1);
        clockwise(2);       temp_ans.push_back(2);
        anti_clockwise(5);  temp_ans.push_back(11);
        anti_clockwise(2);  temp_ans.push_back(8);  
        anti_clockwise(5);  temp_ans.push_back(11);
        clockwise(2);       temp_ans.push_back(2);
        clockwise(5);       temp_ans.push_back(5);
        anti_clockwise(2);  temp_ans.push_back(8);
        anti_clockwise(1);  temp_ans.push_back(7);
        
        clockwise(2);       temp_ans.push_back(2);
        clockwise(5);       temp_ans.push_back(5);
        anti_clockwise(2);  temp_ans.push_back(8);
        anti_clockwise(5);  temp_ans.push_back(11);
        anti_clockwise(2);  temp_ans.push_back(8);
        clockwise(1);       temp_ans.push_back(1);
        clockwise(2);       temp_ans.push_back(2);
        anti_clockwise(1);  temp_ans.push_back(7);
    }
    while(true){
        if(i==5)
            i=1;
        vector<int> face1=fmat[i][5].v2;
        
        vector<int> final=face(i);
        int rt=rot(face1,final,5);
        // cout<<rt<<" ";
        if(rt>=6)
            anti_clockwise(rt-6);
        else if(rt<6 && rt>=0)
            clockwise(rt);
        else
            break;
        temp_ans.push_back(rt);
    }
    cout<<temp_ans.size()<<"\n";
    for(auto x:temp_ans)
        cout<<x<<" ";
    
}

void pll_part2(){
    vector<int> temp_ans;
    bool line=false;
    int i;
    for( i=1;i<5;i++){
        vector<int> middle=fmat[i][1].v2;
        if( equalvector(middle,face(i)))
        {
            line=true;
            break;
        }
    }
    if(line){
        int f,l,r;
        if(i==1){ f=4; l=2; r=3; }
        else if(i==2){ f=3; l=4; r=1; }
        else if(i==3){ f=2; l=1; r=4; }
        else { f=1; l=3; r=2; }
        
        if(equalvector(cross_product(fmat[l][1].v2,face(l)),{0 ,0,0} )){
            clockwise(r);    temp_ans.push_back(r);
            anti_clockwise(5);   temp_ans.push_back(11);
            clockwise(r);       temp_ans.push_back(r);
            clockwise(5);   temp_ans.push_back(5);
            clockwise(r);   temp_ans.push_back(r);
            clockwise(5);   temp_ans.push_back(5);
            clockwise(r);   temp_ans.push_back(r);
            anti_clockwise(5);  temp_ans.push_back(11);
            anti_clockwise(r);  temp_ans.push_back(r+6);
            anti_clockwise(5);  temp_ans.push_back(11);
            clockwise(r);   temp_ans.push_back(r);
            clockwise(r);   temp_ans.push_back(r);
            
        }
        else{
            anti_clockwise(l);  temp_ans.push_back(l+6);
            clockwise(5);       temp_ans.push_back(5);
            anti_clockwise(l);  temp_ans.push_back(l+6);
            anti_clockwise(5);  temp_ans.push_back(11);
            anti_clockwise(l);  temp_ans.push_back(l+6);
            anti_clockwise(5);  temp_ans.push_back(11);
            anti_clockwise(l);  temp_ans.push_back(l+6);
            clockwise(5);       temp_ans.push_back(5);
            clockwise(l);       temp_ans.push_back(l);
            clockwise(5);       temp_ans.push_back(5);
            clockwise(l);       temp_ans.push_back(l);
            clockwise(l);       temp_ans.push_back(l);
            
        }
    }
    else{
        
        if(equalvector(fmat[1][1].v2,{-1,0,0})){
            clockwise(2);       temp_ans.push_back(2);
            anti_clockwise(3);  temp_ans.push_back(9);
            clockwise(2);       temp_ans.push_back(2);
            anti_clockwise(3);  temp_ans.push_back(9);
            anti_clockwise(0);  temp_ans.push_back(6);
            clockwise(2);       temp_ans.push_back(2);
            anti_clockwise(3);  temp_ans.push_back(9);
            clockwise(2);       temp_ans.push_back(2);
            anti_clockwise(3);  temp_ans.push_back(9);
            clockwise(5);       temp_ans.push_back(5);
            clockwise(5);       temp_ans.push_back(5);
            clockwise(2);       temp_ans.push_back(2);
            anti_clockwise(3);  temp_ans.push_back(9);
            clockwise(2);       temp_ans.push_back(2);
            anti_clockwise(3);  temp_ans.push_back(9);
            anti_clockwise(0);  temp_ans.push_back(6);
            clockwise(2);       temp_ans.push_back(2);
            anti_clockwise(3);  temp_ans.push_back(9);
            clockwise(2);       temp_ans.push_back(2);
            anti_clockwise(3);  temp_ans.push_back(9);
        }
        else{
            if(equalvector(fmat[1][1].v2,{0,1,0})){
                clockwise(2);       temp_ans.push_back(2);
                anti_clockwise(3);  temp_ans.push_back(9);
                anti_clockwise(4);  temp_ans.push_back(10);
                clockwise(2);       temp_ans.push_back(2);
                anti_clockwise(3);  temp_ans.push_back(9);  
                clockwise(2);       temp_ans.push_back(2);
                anti_clockwise(3);  temp_ans.push_back(9);
                anti_clockwise(1);  temp_ans.push_back(7);
                clockwise(2);       temp_ans.push_back(2);
                anti_clockwise(3);  temp_ans.push_back(9);
                clockwise(2);       temp_ans.push_back(2);
                anti_clockwise(3);  temp_ans.push_back(9);
                anti_clockwise(4);  temp_ans.push_back(10);
                clockwise(2);       temp_ans.push_back(2);
                anti_clockwise(3);  temp_ans.push_back(9);
                clockwise(0);       temp_ans.push_back(0);
                clockwise(0);       temp_ans.push_back(0);
                clockwise(2);       temp_ans.push_back(2);
                anti_clockwise(3);  temp_ans.push_back(9);
                clockwise(2);       temp_ans.push_back(2);
                anti_clockwise(3);  temp_ans.push_back(9);
                clockwise(5);       temp_ans.push_back(5);
            }
            else{
                clockwise(1);       temp_ans.push_back(1);
                anti_clockwise(4);  temp_ans.push_back(10);
                anti_clockwise(2);  temp_ans.push_back(8);
                clockwise(1);       temp_ans.push_back(1);
                anti_clockwise(4);  temp_ans.push_back(10);
                clockwise(1);       temp_ans.push_back(1);
                anti_clockwise(4);  temp_ans.push_back(10);
                anti_clockwise(3);  temp_ans.push_back(9);
                clockwise(1);       temp_ans.push_back(1);
                anti_clockwise(4);  temp_ans.push_back(10);
                clockwise(1);       temp_ans.push_back(1);
                anti_clockwise(4);  temp_ans.push_back(10);
                anti_clockwise(2);  temp_ans.push_back(8);
                clockwise(1);       temp_ans.push_back(1);
                anti_clockwise(4);  temp_ans.push_back(10);
                clockwise(0);       temp_ans.push_back(0);
                clockwise(0);       temp_ans.push_back(0);
                clockwise(1);       temp_ans.push_back(1);
                anti_clockwise(4);  temp_ans.push_back(10);
                clockwise(1);       temp_ans.push_back(1);
                anti_clockwise(4);  temp_ans.push_back(10);
                clockwise(5);       temp_ans.push_back(5);
            }
        }
    }
    
    cout<<temp_ans.size()<<"\n";
    for(auto x:temp_ans)
        cout<<x<<" ";
}


int main(){
	//traversing cube matrix to fill block matrix
	for(int i=0;i<6;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				vector<int> temp;//temp contains coordinate vector
				temp=blockindex(i,j,k);
				int i1=temp[0];
				int j1=temp[1];
				int k1=temp[2];
				//facing contains face vector
				vector<int> facing=face(cube[i][1][1]);//base color facing
				vector<int> pre_vec;
				// pre_vec contains color as 0th index and further indexes store facing of the color
				pre_vec.push_back(cube[i][j][k]);
				for(int a=0;a<3;a++)
					pre_vec.push_back(facing[a]);
				// +1 is used to counter -1 index 
				b[i1+1][j1+1][k1+1].color.push_back(pre_vec);
			}
		}
	}

	int len=0;
	//traversing block matrix to make face matrix
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				vector<int> var;
				if(i==1 && j==1 && k==1)// origin contain no color 
				    continue;
				for(auto x:b[i][j][k].color)
				{
				    if(!x.empty())
					    var.push_back(x[0]);//
				}
				//var contains color in block 
				for(int per=0;per<var.size();per++){
				    //each color should be treated as base color once
				    //if not done half of cases are missed
				    swap(var[0],var[per]);
				    vector<int> f_ind;
				    f_ind=findex(var);//passing colors to get the location in face_matrix;
				    vector<int> block_vec={i-1,j-1,k-1};
				    vector<int> face_vec;
				    for(auto x:b[i][j][k].color){
				        if(x[0]==var[0]){
				            face_vec.push_back(x[1]);
				            face_vec.push_back(x[2]);
				            face_vec.push_back(x[3]);
				        }
				    }
				    fmat[f_ind[0]][f_ind[1]].v1=block_vec;
				    fmat[f_ind[0]][f_ind[1]].v2=face_vec;
				    
				}
		}}}



clockwise(2);
clockwise(3);
anti_clockwise(1);
clockwise(2);
clockwise(3);
anti_clockwise(1);
anti_clockwise(2);
clockwise(4);
clockwise(5);
anti_clockwise(0);
clockwise(2);
clockwise(3);
anti_clockwise(1);
clockwise(2);
clockwise(3);
clockwise(2);anti_clockwise(1);clockwise(5);clockwise(3);clockwise(3);anti_clockwise(1);

printcube();

cout<<"\n------   step 1   -------------\n";
step1();
cout<<"\n------   step 2   -------------\n";
step2();
cout<<"\n------   step 3   -------------\n";
step3();
cout<<"\n------   step 4   -------------\n";
oll();
cout<<"\n------   step 5   -------------\n";
pll_part1();
cout<<"\n------   step 6   -------------\n";
pll_part2();

// clockwise(5);
// clockwise(5);
cout<<"\n----------------------\n";
printcube();


}

