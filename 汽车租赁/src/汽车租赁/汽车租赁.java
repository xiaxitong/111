package ��������;
import java.util.*;
import java.io.IOException;
abstract class Car{
	protected String carname;//����
	protected String carlabel;//����Ʒ��
	protected String carnumber;//���ƺ�
	protected double carcount;//��������
	abstract double getrentprice(int day);
	abstract void displayInfo();
}
class Small_car extends Car{//�γ�
	private double dayrent;
	Small_car(){}
	Small_car(String carname,String carlabel,String carnumber,int dayrent,double carcount){
		this.carname =carname;
		this.carlabel=carlabel;
		this.carnumber =carnumber;
		this.dayrent=dayrent;
		this.carcount=carcount;
	}
	void displayInfo() {
		System.out.println(this.carname+"   "+this.carlabel +"   "+this.carnumber  +"   "+this.dayrent +"   "+this.carcount );
	}
	double getrentprice(int day) {
		return this.dayrent *day;
	}
}
class Big_car extends Car{//�ͳ�
	private double dayrent1;
	private double dayrent2;
	private int seat;
	Big_car(){}
	Big_car(String carname,String carlabel,String carnumber,int dayrent1,int dayrent2,int seat,double carcount){
		this.carname =carname;
		this.carlabel=carlabel;
		this.carnumber =carnumber;
		this.dayrent1=dayrent1;
		this.dayrent2=dayrent2;
		this.carcount=carcount;
		this.seat=seat;
	}
	void displayInfo() {
		if(this.seat<=16)
			System.out.println(this.carname+"                   "+this.carlabel +"           "+this.carnumber  +"   "+this.dayrent1+"       "+this.seat +"      "+this.carcount );
		else
			System.out.println(this.carname+"                   "+this.carlabel +"           "+this.carnumber  +"   "+this.dayrent2+"      "+this.seat +"      "+this.carcount );
	}
	double getrentprice(int day) {
		if(this.seat<17)
		   return this.dayrent1 *day;
		else
		   return this.dayrent2 *day;
	}
}
class Car_client{
	double price;
	static double allprice =0.0;
	char chooseserve(char flag) {
		if(flag=='0')
			System.out.println("\tall price="+this.allprice);
		return flag;
	}//ѡ����
	int choosecar() {
		Scanner sc=new Scanner(System.in);
		int number=sc.nextInt();
		return number;
	}//ѡ��ڼ��ų�
	int chooseday() {
		Scanner sc=new Scanner(System.in);
		int day=sc.nextInt();
		return day;
	}//ѡ����������
}
class Car_serve_system{
	Small_car scar[];
	Big_car bcar[];
	Car_client client;
	void serve(char flag) {
		if(flag=='0')
			this.exitSystem();
		if(flag=='1')
			this.display_scar();
		if(flag=='2')
			this.display_bcar();
	}//ȷ����γ����ǿͳ�
	void initcar(){
		scar=new Small_car[3];
		bcar=new Big_car[2];
		scar[0]=new Small_car("����CRV","����","��NY28588",600,10);
		scar[1]=new Small_car("����Esc","����","��NNN3284",500,10);
		scar[2]=new Small_car("����HRV","����","��NT43765",400,10);
		bcar[0]=new Big_car("�ͳ�","����","��WN168463",800,1000,15,10);
		bcar[1]=new Big_car("�ͳ�","����","��NTT24632",800,1000,40,10);
	}//���ӵ���Ϣ
	void display_scar() {
		System.out.println("��������"+"    "+"����Ʒ��"+"    "+"���ƺ�"+"    "+"�����"+"    "+"��������");
		for(Small_car sc:scar){
			sc.displayInfo();
		}
		System.out.print("��ѡ�����ڼ�������");
	}//��γ��������Ϣ
	void display_bcar() {
		System.out.println("��������"+"         "+"����Ʒ��"+"          "+"���ƺ�"+"            "+"�����"+"           "+"��λ��"+"          "+"��������");
		for(Big_car bc:bcar){
			bc.displayInfo();
		}
		System.out.print("��ѡ�����ڼ�������");
	}//��ͳ��������Ϣ
	void exitSystem() {
		System.exit(0);
	}//�˳��⳵ϵͳ
	void give_scar(int flag) {
		if(scar[flag-1].carcount>0){
			System.out.println("��ѡ�����������");
			this.client.price=this.scar[flag-1].getrentprice(this.client.chooseday());
			this.scar[flag-1].carcount--;
			System.out.println("�����Ϊ��"+this.client.price);
			this.client.allprice+=this.client.price;
		}
		else{
			System.out.print("�ó���ȫ�������");
			this.give_scar(this.client.choosecar());
		}
	}//����γ������
	void give_bcar(int flag) {
		if(bcar[flag-1].carcount>0){
			System.out.println("��ѡ�����������");
			this.client.price=this.bcar[flag-1].getrentprice(this.client.chooseday());
			this.bcar[flag-1].carcount--;
			System.out.println("�����Ϊ��"+this.client.price);
			this.client.allprice+=this.client.price;
		}
		else{
			System.out.print("�ó���ȫ�������");
			this.give_scar(this.client.choosecar());
		}
	}//����ͳ������
}
public class �������� {
	public static void main(String[] args) throws IOException{
		Scanner sc=new Scanner(System.in);
		Car_serve_system carsystem=new Car_serve_system();
		Car_client carclient=new Car_client();
		carsystem.client=carclient;
		carsystem.initcar();
		char flag='8';
		while(flag!='0'){
			System.out.println("   0:�˳�������"+"    "+"1:��γ�"+"    "+"2:��ͳ�");
			flag=(char)System.in.read();
			if(flag=='1'){
				carsystem.serve(flag);
				carsystem.give_scar(carclient.choosecar());
			}
			if(flag=='2')
				carsystem.serve(flag);
				carsystem.give_bcar(carclient.choosecar());
		}
	}

}