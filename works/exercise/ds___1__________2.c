//��Ƶͳ��-�ֵ���ʵ��
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define NUM 100		//�����ֵ
#define MAXWORD 128	//��󵥴ʳ���
#define FREQ	2000	//��Ƶ������󳤶�
	
struct wnode {
    char *word;
	struct wnode *next; //�������ɴ�Ƶ��ͬ�ĵ��ʶ�
} ; //���ʽڵ�
struct wnode1 {
    char *word;
    int count;
	struct wnode1 *next; //�������ɰ���Ƶ���������
} ; ////���ʽڵ�
struct tnode {		// word tree 
	int count;
	char isleaf;	// is or not a leaf node
	struct tnode *ptr[26];
};

struct wqueue {		//���ʶ�ͷβ�ṹ
	struct wnode *head;
	struct wnode *rear;
};

struct wnode1 *Head=NULL;		//��Ƶ����FREQ�ĵ�����������ͷ
struct wqueue Headlist[FREQ]={0 };	//Headlist[i]�Ǵ�ƵΪi�ĵ��ʶ� 
char *Wordptr;

int getWord(FILE *fp,char *w);
struct tnode *talloc(); //����һ�����ڵ㣬����ʼ��
struct wnode *walloc(char *s); //����һ����������ڵ㣬�����ַ���s�������ڵ���
struct wnode1 *walloc1(char *s,int count); //alloc a wnode1, and init it with s and count 
void wordTree(struct tnode *root,char *w);
void vistTree( struct tnode *p,char *w); //����������������һ�������������
void addQueue(int index, struct wnode *p); //�����ʽڵ�ӵ���Ӧ����β
void insertSortLink(struct wnode1 *p); //��һ�����ʽڵ㰴��Ƶ�ӵ�����������
void printWord(FILE *fp); //����Ƶ�������Ƶ���ļ��У�����ǰNUM���������Ļ

int main()
{
    char filename[32], word[MAXWORD];
    FILE *bfp,*out;
	struct tnode *root;

//    scanf("%s", filename);
    if((bfp = fopen("article.txt", "r")) == NULL){
        fprintf(stderr, "%s  can't open!\n","article.txt");
        return -1;
     }
    if((out = fopen("wordfreq.txt", "w")) == NULL){
        fprintf(stderr, "%s  can't open!\n","wordfreq.txt");
        return -1;
     }
	root = talloc(); //word tree's first node

    while(getWord(bfp,word) != EOF) //���ļ��ж���һ������
         wordTree(root,word);
	Wordptr = word;
    vistTree(root,word);  //�������������,����һ������Ƶ���������
	printWord(out); //����Ƶ��������ʼ�Ƶ��

	fclose(bfp); fclose(out);

    return 0;
} 

/*���ļ��ж���һ�����ʣ�ֻ����ĸ��ɵĴ�������ת����Сд��ĸ*/
int getWord(FILE *fp, char *w)
{
    int c;
	char *s=w;
    while(!isalpha(c=fgetc(fp)))  
        if(c == EOF) return c;  
		else continue;
    *s++ = c;
    while((c=fgetc(fp))!=EOF){
         if(!isalpha(c)) break; 
         *s++ = c;
    }
    *s='\0';
    while(*w = tolower(*w)) w++;
    return 1;
} 

void wordTree(struct tnode *root,char *w)  /* install w at or below p */
{
	struct tnode *p;

	for(p=root; *w != '\0'; w++){
		if(p->ptr[*w-'a'] == NULL) {
			p->ptr[*w-'a'] = talloc();
			p->isleaf = 0;
		}
		p = p->ptr[*w-'a'];	
	}
	p->count++;
}

struct tnode *talloc()
{
	struct tnode *p;
	int i;

	p = (struct tnode *)malloc(sizeof(struct tnode));
//	if(p==NULL) {printf("memory is full!\n");exit(-1);}
	p->count = 0;
	p->isleaf = 1; // is a leaf
	for(i=0; i<26; i++)
		p->ptr[i] = NULL;
	return p;
}

void vistTree(struct tnode *p,char *w) /* print tree p recursirely */
{
	int i;
	struct wnode *pw;
	struct wnode1 *pw1;
	
	if(p->count > 0)
		if(p->count < FREQ ) {
			*w = '\0';
			pw = walloc(Wordptr); //is a leaf
			addQueue(p->count,pw);
		}
		else {
			*w = '\0';
			pw1 = walloc1(Wordptr, p->count);
			insertSortLink(pw1);
		}
	for(i=0; i<26&&!p->isleaf; i++){
		if(p->ptr[i] != NULL){
			*w = i+'a';
			vistTree(p->ptr[i], w+1);
		}
	}
}

struct wnode *walloc(char *s) //alloc a wnode, and save s word into the node 
{
	struct wnode *p;

	p = (struct wnode *)malloc(sizeof(struct wnode));
	p->word = (char *)malloc(strlen(s)+1);
	strcpy(p->word, s);
	p->next = NULL;
	return p;
}

struct wnode1 *walloc1(char *s,int count) //alloc a wnode, and save s word into the node 
{
	struct wnode1 *p;

	p = (struct wnode1 *)malloc(sizeof(struct wnode1));
	p->word = (char *)malloc(strlen(s)+1);
	strcpy(p->word, s);
	p->count = count;
	p->next = NULL;
	return p;
}

void addQueue(int index, struct wnode *p)
{
	if(Headlist[index].head != NULL){
		Headlist[index].rear->next = p;
		Headlist[index].rear = p;
	}
	else
		Headlist[index].head = Headlist[index].rear = p;
}

void insertSortLink(struct wnode1 *p)
{
	struct wnode1 *q,*r;
	if(Head == NULL)
		Head = p;
	else if(p->count > Head->count) {
		p->next = Head;
		Head = p;
	}
	else {
		for(q = Head; q!=NULL && (p->count<=q->count); r=q, q=q->next)
			;
		p->next = q;
		r->next = p; 
	}
}

void printWord(FILE *fp)
{
	int i,n=0;
	struct wnode *p;
	struct wnode1 *q;

	for(q=Head; q != NULL; q=q->next){
		fprintf(fp,"%s %d\n",q->word,q->count);
		if(n < NUM)
			printf("%s %d\n",q->word,q->count);
		n++;
	}
	for(i=FREQ-1; i>0; i--){
		if(Headlist[i].head == NULL) continue;
		p = Headlist[i].head;
		for(;p != NULL; p=p->next){
			fprintf(fp,"%s %d\n",p->word,i);
			if(n < NUM)
				printf("%s %d\n",p->word,i);
			n++;
		}
	}
//	printf("---%d---\n",n);
}


