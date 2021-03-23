//

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int itemp,j;
    *returnSize=0;
    for(int i=0;i<numsSize;++i)
    {
        itemp=target-nums[i];
        for(j=i+1;j<numsSize;++j)
        {
            if((nums[j]+nums[i])==target)
            {
                *returnSize=2;
                int *ret=(int *)malloc(sizeof(int)*2);
                ret[0]=i;
                ret[1]=j;
                return ret;
            }
        }
    }
    return NULL;
}
//
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    for (int i = 0; i < numsSize; ++i) 
    {
        for (int j = i + 1; j < numsSize; ++j) 
        {
            if (nums[i] + nums[j] == target) 
            {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
//

//Hash table

struct hashtablet
{
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashtablet *ph;

void insertt(int ikey,int ival)
{
    struct hashtablet *htemp;
    HASH_FIND_INT(ph,&ikey,htemp);
    if(htemp==NULL)
    {
        struct hashtablet *it=(struct hashtablet *)malloc(sizeof(struct hashtablet));
        it->key=ikey;
        it->val=ival;
        HASH_ADD_INT(ph,key,it);
    }
    else
    {
        htemp->val=ival;
    }
    return;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    ph=NULL;
    for(int i=0;i<numsSize;i++)
    {
        struct hashtablet *try;
        int itemp=target-nums[i];
        HASH_FIND_INT(ph,&itemp,try);
        if(try!=NULL)
        {
            int *ret=malloc(sizeof(int)*2);
            ret[0]=i;
            ret[1]=try->val;
            *returnSize=2;
            return ret;
        }
        insertt(nums[i],i);
    }
    *returnSize=0;
    return NULL;
}



//
struct hashTable {
    int key;//值 hash表只关心是否存在某个key值
    int val;//下标
    UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(int ikey) {
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);//在表中找值为 ikey 的地址并赋给 s , & +想查询的值
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable* it = find(ikey);
    if (it == NULL) {
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);//增加一个  key指hash表中的key值的 “变量名”
    } else {
        it->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}
