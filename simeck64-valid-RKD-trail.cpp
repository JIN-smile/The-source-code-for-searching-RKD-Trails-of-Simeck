#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void printhead()
{
    cout << "(set-logic QF_ABV)" << endl;
    cout << "(set-info :smt-lib-version 2.5)" << endl;
    cout << "(set-option :produce-models true)" <<endl;
}



void declare(int r)
{

    cout << "(declare-fun dk0 () (_ BitVec 32)) " <<endl;
    cout << "(declare-fun dk1 () (_ BitVec 32)) " <<endl;
    cout << "(declare-fun dk2 () (_ BitVec 32)) " <<endl;
    cout << "(declare-fun dk () (_ BitVec 32)) " <<endl;



    for(int i=1; i<=r; i++)
    {
        cout << "(declare-fun lft_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun rgt_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun key_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun d_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun varibits_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun doublebits_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun z_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun wr_" << i << " () (_ BitVec 32)) " <<endl;

    }

    cout << "(declare-fun lft_" << r+1 << " () (_ BitVec 32)) " ;
    cout << "(declare-fun rgt_" << r+1 << " () (_ BitVec 32)) " ;
    cout << endl;



    for(int i=1; i<=r; i++)
    {
        cout << "(declare-fun klft_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun krgt_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun c_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun kd_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun kvaribits_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun kdoublebits_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun kz_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun kwr_" << i << " () (_ BitVec 32)) " <<endl;

    }

    cout << "(declare-fun klft_" << r+1 << " () (_ BitVec 32)) " ;
    cout << "(declare-fun krgt_" << r+1 << " () (_ BitVec 32)) " ;
    cout << endl;

    cout << "(declare-fun key_weight () (_ BitVec 32)) " <<endl;
    cout << "(declare-fun plain_weight () (_ BitVec 32)) " <<endl;
    cout << "(declare-fun sum_weight () (_ BitVec 32)) " <<endl;
    cout << endl;



    //weak key
    for(int i=1; i<=(r+1); i++)
    {
        cout << "(declare-fun value_k_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun value_kpie_" << i << " () (_ BitVec 32)) " <<endl;
    }

    for(int i=1; i<=(r+1); i++)
    {
        cout << "(declare-fun value_lft_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun value_rgt_" << i << " () (_ BitVec 32)) " <<endl;

        cout << "(declare-fun value_lftpie_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun value_rgtpie_" << i << " () (_ BitVec 32)) " <<endl;

        cout << "(declare-fun chafen_lft_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun chafen_rgt_" << i << " () (_ BitVec 32)) " <<endl;
        cout << "(declare-fun chafen_k_" << i << " () (_ BitVec 32)) " <<endl;
    }




     //define hamming weight
    cout <<"(define-fun w_H0 ((x (_ BitVec 32))) (_ BitVec 32)"<<endl;
    cout <<"      (bvadd (bvand x #x55555555 )"<<endl;
    cout <<"             (bvand (bvlshr x #x00000001) #x55555555 )))"<<endl;
    cout <<"(define-fun w_H1 ((x (_ BitVec 32))) (_ BitVec 32)"<<endl;
    cout <<"      (bvadd (bvand x #x33333333 )"<<endl;
    cout <<"             (bvand (bvlshr x #x00000002) #x33333333 )))"<<endl;
    cout <<"(define-fun w_H2 ((x (_ BitVec 32))) (_ BitVec 32)"<<endl;
    cout <<"      (bvadd (bvand x #x0f0f0f0f )"<<endl;
    cout <<"             (bvand (bvlshr x #x00000004) #x0f0f0f0f)))"<<endl;
    cout <<"(define-fun w_H3 ((x (_ BitVec 32))) (_ BitVec 32)"<<endl;
    cout <<"      (bvadd (bvand x #x00ff00ff )"<<endl;
    cout <<"             (bvand (bvlshr x #x00000008) #x00ff00ff )))"<<endl;
    cout <<"(define-fun w_H4 ((x (_ BitVec 32))) (_ BitVec 32)"<<endl;
    cout <<"      (bvadd (bvand x #x0000ffff )"<<endl;
    cout <<"             (bvand (bvlshr x #x00000010) #x0000ffff )))"<<endl;
    cout <<"(define-fun w_H ((x (_ BitVec 32))) (_ BitVec 32) (w_H4 (w_H3 (w_H2 (w_H1 (w_H0 x))))))"<<endl;

}

void cczformula_delta(int r)
{



    for(int i=1; i<=r;i++)
    {
        if((i == 1) || (i == 2) || (i == 3) || (i == 4)
           || (i == 5) || (i == 6) || (i == 12)||
           (i == 17) || (i == 18) || (i == 22) ||
           (i == 24) || (i == 27) || (i == 28) ||
           (i == 29) || (i == 30) || (i == 32) ||
           (i == 36) || (i == 37) || (i == 38) ||
           (i == 41) || (i == 44))
        {
            cout<< " (assert (= c_"<<i<<" #xfffffffd))"<<endl;
        }
        else
        {
            cout<< " (assert (= c_"<<i<<" #xfffffffc))"<<endl;
        }

    }



    cout<< " (assert (= krgt_1  dk0 ))"<<endl;

    cout<< " (assert (= kvaribits_1  (bvor  ((_ rotate_left 5) dk0)  dk0)))"<<endl;

    cout<< " (assert (= kdoublebits_1  (bvand  (bvand (bvxor ((_ rotate_left 5) dk0) #xffffffff)  dk0) ((_ rotate_left 10) dk0))))"<<endl;

    cout<< " (assert (= #x00000000 (bvand  (bvxor kvaribits_1 #xffffffff)  kd_1))) "<<endl;

    cout<< " (assert (= #x00000000 (bvand  (bvxor ((_ rotate_left 5) kd_1) kd_1) kdoublebits_1))) "<<endl;

    cout<< " (assert (= klft_1  (bvxor (bvxor dk kd_1 ) ((_ rotate_left 1) dk0))))"<<endl;

    cout<< " (assert (= kz_1 (bvxor kvaribits_1 kdoublebits_1)))"<<endl;


    cout<< " (assert (= krgt_2  dk1 ))"<<endl;

    cout<< " (assert (= kvaribits_2  (bvor  ((_ rotate_left 5) dk1)  dk1)))"<<endl;

    cout<< " (assert (= kdoublebits_2  (bvand  (bvand (bvxor ((_ rotate_left 5) dk1) #xffffffff)  dk1) ((_ rotate_left 10) dk1))))"<<endl;

    cout<< " (assert (= #x00000000 (bvand  (bvxor kvaribits_2 #xffffffff)  kd_2))) "<<endl;

    cout<< " (assert (= #x00000000 (bvand  (bvxor ((_ rotate_left 5) kd_2) kd_2) kdoublebits_2))) "<<endl;

    cout<< " (assert (= klft_2  (bvxor (bvxor krgt_1 kd_2 ) ((_ rotate_left 1) dk1))))"<<endl;

    cout<< " (assert (= kz_2 (bvxor kvaribits_2 kdoublebits_2)))"<<endl;


    cout<< " (assert (= krgt_3  dk2 ))"<<endl;

    cout<< " (assert (= kvaribits_3  (bvor  ((_ rotate_left 5) dk2)  dk2)))"<<endl;

    cout<< " (assert (= kdoublebits_3  (bvand  (bvand (bvxor ((_ rotate_left 5) dk2) #xffffffff)  dk2) ((_ rotate_left 10) dk2))))"<<endl;

    cout<< " (assert (= #x00000000 (bvand  (bvxor kvaribits_3 #xffffffff)  kd_3))) "<<endl;

    cout<< " (assert (= #x00000000 (bvand  (bvxor ((_ rotate_left 5) kd_3) kd_3) kdoublebits_3))) "<<endl;

    cout<< " (assert (= klft_3  (bvxor (bvxor krgt_2 kd_3 ) ((_ rotate_left 1) dk2))))"<<endl;

    cout<< " (assert (= kz_3 (bvxor kvaribits_3 kdoublebits_3)))"<<endl;

    for(int i=1; i<=(r-3);i++)
    {

        cout<< " (assert (= krgt_"<< i+3 <<"  klft_"<< i<<" ))"<<endl;

        cout<< " (assert (= klft_"<< i+3 <<"  (bvxor (bvxor krgt_"<<i+2<<" kd_"<<i+3<<" ) ((_ rotate_left 1) klft_"<<i<<"))))"<<endl;

        cout<< " (assert (= kvaribits_"<<i+3<<"  (bvor  ((_ rotate_left 5) klft_"<< i<<")  klft_"<< i<<")))"<<endl;

        cout<< " (assert (= kdoublebits_"<<i+3<<"  (bvand  (bvand (bvxor ((_ rotate_left 5) klft_"<< i<<") #xffffffff)  klft_"<< i<<") ((_ rotate_left 10) klft_"<< i<<"))))"<<endl;

        cout<< " (assert (= #x00000000 (bvand  (bvxor kvaribits_"<<i+3<<" #xffffffff)  kd_"<<i+3<<"))) "<<endl;

        cout<< " (assert (= #x00000000 (bvand  (bvxor ((_ rotate_left 5) kd_"<<i+3<<") kd_"<<i+3<<") kdoublebits_"<<i+3<<"))) "<<endl;

        cout<< " (assert (= kz_"<< i+3 <<" (bvxor kvaribits_"<<i+3<<" kdoublebits_"<<i+3<<")))"<<endl;

    }



    cout<< " (assert (= key_1  dk ))"<<endl;

    cout<< " (assert (= rgt_2  lft_1 ))"<<endl;

    cout<< " (assert (= varibits_1  (bvor  ((_ rotate_left 5) lft_1)  lft_1)))"<<endl;

    cout<< " (assert (= doublebits_1  (bvand  (bvand (bvxor ((_ rotate_left 5) lft_1) #xffffffff)  lft_1) ((_ rotate_left 10) lft_1))))"<<endl;

    cout<< " (assert (= #x00000000 (bvand  (bvxor varibits_1 #xffffffff)  d_1))) "<<endl;

    cout<< " (assert (= #x00000000 (bvand  (bvxor ((_ rotate_left 5) d_1) d_1) doublebits_1))) "<<endl;

    cout<< " (assert (= lft_2  (bvxor (bvxor rgt_1 d_1) (bvxor ((_ rotate_left 1) lft_1) key_1))))"<<endl;

    cout<< " (assert (= z_1 (bvxor varibits_1 doublebits_1)))"<<endl;



    for(int i = 1; i <= (r-1);i++)
    {
        cout<< " (assert (= key_"<<i+1<<"  krgt_"<<i<<"))"<<endl;

        cout<< " (assert (= rgt_"<< i+2 <<"  lft_"<< i+1<<" ))"<<endl;

        cout<< " (assert (= varibits_"<< i+1 <<"  (bvor  ((_ rotate_left 5) lft_"<< i+1 <<")  lft_"<< i+1 <<")))"<<endl;

        cout<< " (assert (= doublebits_"<< i+1 <<"  (bvand  (bvand (bvxor ((_ rotate_left 5) lft_"<< i+1 <<") #xffffffff)  lft_"<< i+1 <<") ((_ rotate_left 10) lft_"<< i+1 <<"))))"<<endl;

        cout<< " (assert (= #x00000000 (bvand  (bvxor varibits_"<< i+1 <<" #xffffffff)  d_"<< i+1 <<"))) "<<endl;

        cout<< " (assert (= #x00000000 (bvand  (bvxor ((_ rotate_left 5) d_"<< i+1 <<") d_"<< i+1 <<") doublebits_"<< i+1 <<"))) "<<endl;

        cout<< " (assert (= lft_"<< i+2 <<"  (bvxor (bvxor rgt_"<<i+1<<" d_"<<i+1<<") (bvxor ((_ rotate_left 1) lft_"<<i+1<<") key_"<<i+1<<"))))"<<endl;

        cout<< " (assert (= z_"<< i+1 <<" (bvxor varibits_"<< i+1 <<" doublebits_"<< i+1 <<")))"<<endl;

    }


}



void cczformula_value(int r)
{


    for(int i=1; i<=(r-4);i++)
    {

        cout<< " (assert (= value_k_"<< i+4 <<"  (bvxor (bvxor (bvxor (bvand ((_ rotate_left 5) value_k_"<< i+1 <<") value_k_"<< i+1 <<") ((_ rotate_left 1) value_k_"<< i+1 <<")) c_"<<i<<") value_k_"<< i <<")))"<<endl;

    }

    for(int i=1; i<=(r-4);i++)
    {

        cout<< " (assert (= value_kpie_"<< i+4 <<"  (bvxor (bvxor (bvxor (bvand ((_ rotate_left 5) value_kpie_"<< i+1 <<") value_kpie_"<< i+1 <<") ((_ rotate_left 1) value_kpie_"<< i+1 <<")) c_"<<i<<") value_kpie_"<< i <<")))"<<endl;

    }

    for(int i=1; i<=r;i++)
    {

        cout<< " (assert (= chafen_k_"<< i <<" (bvxor  value_k_"<< i <<"  value_kpie_"<< i <<")))"<<endl;


    }

    for(int i=1; i<=r;i++)
    {

        cout<< " (assert (= chafen_k_"<< i <<"  key_"<<i<<"))"<<endl;


    }


    for(int i=1; i<=r;i++)
    {
        cout<< " (assert (= value_rgt_"<< i+1 <<"  value_lft_"<< i <<"))"<<endl;

        cout<< " (assert (= value_lft_"<< i+1 <<"  (bvxor (bvxor (bvxor (bvand ((_ rotate_left 5) value_lft_"<< i <<") value_lft_"<< i <<") ((_ rotate_left 1) value_lft_"<< i <<")) value_rgt_"<< i <<") value_k_"<< i <<")))"<<endl;

    }

    for(int i=1; i<=r;i++)
    {
        cout<< " (assert (= value_rgtpie_"<< i+1 <<"  value_lftpie_"<< i <<"))"<<endl;

        cout<< " (assert (= value_lftpie_"<< i+1 <<"  (bvxor (bvxor (bvxor (bvand ((_ rotate_left 5) value_lftpie_"<< i <<") value_lftpie_"<< i <<") ((_ rotate_left 1) value_lftpie_"<< i <<")) value_rgtpie_"<< i <<") value_kpie_"<< i <<")))"<<endl;

    }

    for(int i=1; i<=(r+1);i++)
    {

        cout<< " (assert (= chafen_lft_"<< i <<" (bvxor  value_lft_"<< i <<"  value_lftpie_"<< i <<")))"<<endl;
        cout<< " (assert (= chafen_rgt_"<< i <<" (bvxor  value_rgt_"<< i <<"  value_rgtpie_"<< i <<")))"<<endl;


    }

    for(int i=1; i<=(r+1);i++)
    {

        cout<< " (assert (= chafen_lft_"<< i <<"  lft_"<<i<<"))"<<endl;
        cout<< " (assert (= chafen_rgt_"<< i <<"  rgt_"<<i<<"))"<<endl;

    }
}



void objectivefun(int r, int bound)
{

    for(int i=1; i<=r;i++)
    {
        cout<< " (assert (= kwr_"<<i<<" (w_H kz_"<<i<<")))"<<endl;
    }

    cout << " (assert (= key_weight  ";

    for(int i=1; i<=(r-4); i++)
    {
        if(i<(r-4))
        {
            cout << "(bvadd  kwr_"<<i<<" ";
        }

        else
        {
            cout << "kwr_"<< r-4 <<" ";
        }
    }

    for(int i = 1; i < (r-4); i++)
    {
        cout << ")";
    }

    cout << "))"<<endl;



    for(int i=1; i<=r;i++)
    {
        cout<< " (assert (= wr_"<<i<<" (w_H z_"<<i<<")))"<<endl;
    }

    cout << " (assert (= plain_weight ";

    for(int i=1; i<=r; i++)
    {
        if(i<r)
        {
            cout << "(bvadd  wr_"<<i<<" ";
        }

        else
        {
            cout << "wr_"<< r <<" ";
        }
    }

    for(int i = 1 ; i < r ; i++)
    {
        cout << ")";
    }

    cout << "))"<<endl;


    cout<< " (assert (= sum_weight (bvadd key_weight plain_weight)))"<<endl;
    cout<< " (assert (= sum_weight (_ bv"<<bound<<" 32)))"<<endl;


    cout<< " (assert (bvule plain_weight  #x00000040))"<<endl;
    cout<< " (assert (bvugt key_weight  #x00000000))"<<endl;
}



void tail(int r)
{

	cout << "(check-sat)" << endl;



	for(int i=1;i<=(r+1);i++)
	{

	    cout << "(get-value (value_lft_"<< i <<"))" << endl;
	    cout << "(get-value (value_rgt_"<< i <<"))" << endl;

	    cout << "(get-value (value_lftpie_"<< i <<"))" << endl;
	    cout << "(get-value (value_rgtpie_"<< i <<"))" << endl;

	    cout << "(get-value (chafen_lft_"<< i <<"))" << endl;
	    cout << "(get-value (lft_"<< i <<"))" << endl;

	    cout << "(get-value (chafen_rgt_"<< i <<"))" << endl;
	    cout << "(get-value (rgt_"<< i <<"))" << endl;
	}

	for(int i=1;i<=r;i++)
	{

	    cout << "(get-value (value_k_"<< i <<"))" << endl;
	    cout << "(get-value (value_kpie_"<< i <<"))" << endl;

	    cout << "(get-value (chafen_k_"<< i <<"))" << endl;

	    cout << "(get-value (key_"<< i <<"))" << endl;

	    cout << "(get-value (c_"<< i <<"))" << endl;
	}


	cout << "(get-value (dk0))" << endl;
	cout << "(get-value (dk1))" << endl;
	cout << "(get-value (dk2))" << endl;
	cout << "(get-value (dk))" << endl;

	for(int i=1;i<=r;i++)
	{

	    cout << "(get-value (klft_"<< i <<"))" << endl;
	    cout << "(get-value (krgt_"<< i <<"))" << endl;
	    cout << "(get-value (kd_"<< i <<"))" << endl;
	    cout << "(get-value (kz_"<< i <<"))" << endl;
	    cout << "(get-value (kwr_"<< i <<"))" << endl;
	}



	for(int i=1;i<=r;i++)
	{

	    cout << "(get-value (lft_"<< i <<"))" << endl;
	    cout << "(get-value (rgt_"<< i <<"))" << endl;
	    cout << "(get-value (key_"<< i <<"))" << endl;
	    cout << "(get-value (d_"<< i <<"))" << endl;
	    cout << "(get-value (z_"<< i <<"))" << endl;
	    cout << "(get-value (wr_"<< i <<"))" << endl;


	}

	cout << "(get-value (lft_"<< r+1 <<"))" << endl;
    cout << "(get-value (rgt_"<< r+1 <<"))" << endl;

    cout << "(get-value (plain_weight))" << endl;
    cout << "(get-value (key_weight))" << endl;
    cout << "(get-value (sum_weight))" << endl;

	cout << "(exit)" << endl;


}

int main(int argc, char** argv)
{
    int ROUND = atoi(argv[1]);
    int BOUND = atoi(argv[2]);

    printhead();

    declare(ROUND);

    cczformula_delta(ROUND);
    cczformula_value(ROUND);

    objectivefun(ROUND,BOUND);

    tail(ROUND);

    return 0;
}






