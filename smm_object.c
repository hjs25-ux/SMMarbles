//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODENR      100
#define MAX_NODETYPE    7
#define MAX_GRADE       13

#define OBJTYPE_BOARD      0
#define OBJTYPE_GRADE      1
#define OBJTYPE_FOOD       2
#define OBJTYPE_FESTIVAl   3

#define GRADE_Ap           0
#define GRADE_Az           1
#define GRADE_Am           2
#define GRADE_Bp           3
#define GRADE_Bz           4
#define GRADE_Bm           5
#define GRADE_Cp           6
#define GRADE_Cz           7
#define GRADE_Cm           8
#define GRADE_Dp           9
#define GRADE_Dz           10
#define GRADE_Dm           11
#define GRADE_F            12



static char smmObj_nodeName[MAX_NODETYPE][MAX_CHARNAME]=
{
       "lecture",
       "restaturant",
       "laboratory",
       "home",
       "gotoLab",
       "foodChance",
       "festival"         
};

static char smmObj_gradeName[13][MAX_CHARNAME]=
{
       "Ap",
       "Az",
       "Am",
       "Bp",
       "Bz",
       "Bm",
       "Cp",
       "Cz",
       "Cm",
       "Dp",
       "Dz",
       "Dm",
       "F"
};

//structure type definition
typedef struct 
{
        char name[MAX_CHARNAME];
        int objType;
        int type;
        int credit;
        int energy;
        int grade;    
} smmObj_object_t; 


typedef struct
{
        char name[MAX_CHARNAME];
        int energy;        
} smmObj_food_t;

typedef struct
{
        char name[MAX_CHARNAME];
} smmObj_festival_t;



//object generation
void* smmObj_genObject(char* name, int objType, int type, int credit, int energy, int grade) //node group 형성  
{
    smmObj_object_t* ptr;
    ptr = (smmObj_object_t*)malloc(sizeof(smmObj_object_t));
    
    strcpy(ptr->name, name);
    ptr->type = type;
    ptr->objType = objType;
    ptr->credit = credit;
    ptr->energy = energy;
    ptr->grade = grade;
    
    return ((void*)ptr);
}

//food도 동일하게 형성  
//festival도 동일하게 형성  




//member retrieving
char* smmObj_getNodeName(void *ptr)
{
      smmObj_object_t* objPtr = (smmObj_object_t*)ptr;
      return (objPtr->name);
}

/*
int smmObj_getNodeType(int node_nr)
{
      return (smmObj_board[node_nr].type);
}

int smmObj_getNodeCredit(int node_nr)
{
      return (smmObj_board[node_nr].credit);
}

int smmObj_getNodeEnergy(int node_nr)
{
      return (smmObj_board[node_nr].energy);
}

char* smmObj_getTypeName(int node_type)
{
      return (smmObj_nodeName[node_type]);
}
*/

#if 0
//element to string

char* smmObj_getGradeName(smmGrade_e grade)
{
    return smmGradeName[grade];
}
#endif
