package 汽车租赁;
import java.util.*;
import java.io.IOException;
abstract class Car{
	protected String carname;//车名
	protected String carlabel;//车的品牌
	protected String carnumber;//车牌号
	protected double carcount;//车的数量
	abstract double getrentprice(int day);
	abstract void displayInfo();
}
class Small_car extends Car{//轿车
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
class Big_car extends Car{//客车
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
	}//选择车型
	int choosecar() {
		Scanner sc=new Scanner(System.in);
		int number=sc.nextInt();
		return number;
	}//选择第几号车
	int chooseday() {
		Scanner sc=new Scanner(System.in);
		int day=sc.nextInt();
		return day;
	}//选择租赁天数
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
	}//确定租轿车还是客车
	void initcar(){
		scar=new Small_car[3];
		bcar=new Big_car[2];
		scar[0]=new Small_car("本田CRV","本田","京NY28588",600,10);
		scar[1]=new Small_car("福特Esc","福特","京NNN3284",500,10);
		scar[2]=new Small_car("本田HRV","本田","京NT43765",400,10);
		bcar[0]=new Big_car("客车","本田","京WN168463",800,1000,15,10);
		bcar[1]=new Big_car("客车","本田","京NTT24632",800,1000,40,10);
	}//车子的信息
	void display_scar() {
		System.out.println("车的名字"+"    "+"车的品牌"+"    "+"车牌号"+"    "+"日租金"+"    "+"可租数量");
		for(Small_car sc:scar){
			sc.displayInfo();
		}
		System.out.print("请选择租借第几辆车：");
	}//租轿车的输出信息
	void display_bcar() {
		System.out.println("车的名字"+"         "+"车的品牌"+"          "+"车牌号"+"            "+"日租金"+"           "+"座位数"+"          "+"可租数量");
		for(Big_car bc:bcar){
			bc.displayInfo();
		}
		System.out.print("请选择租借第几辆车：");
	}//租客车的输出信息
	void exitSystem() {
		System.exit(0);
	}//退出租车系统
	void give_scar(int flag) {
		if(scar[flag-1].carcount>0){
			System.out.println("请选择租借天数：");
			this.client.price=this.scar[flag-1].getrentprice(this.client.chooseday());
			this.scar[flag-1].carcount--;
			System.out.println("总租金为："+this.client.price);
			this.client.allprice+=this.client.price;
		}
		else{
			System.out.print("该车已全部被租出");
			this.give_scar(this.client.choosecar());
		}
	}//计算轿车总租金
	void give_bcar(int flag) {
		if(bcar[flag-1].carcount>0){
			System.out.println("请选择租借天数：");
			this.client.price=this.bcar[flag-1].getrentprice(this.client.chooseday());
			this.bcar[flag-1].carcount--;
			System.out.println("总租金为："+this.client.price);
			this.client.allprice+=this.client.price;
		}
		else{
			System.out.print("该车已全部被租出");
			this.give_scar(this.client.choosecar());
		}
	}//计算客车总租金
}
public class 汽车租赁 {
	public static void main(String[] args) throws IOException{
		Scanner sc=new Scanner(System.in);
		Car_serve_system carsystem=new Car_serve_system();
		Car_client carclient=new Car_client();
		carsystem.client=carclient;
		carsystem.initcar();
		char flag='8';
		while(flag!='0'){
			System.out.println("   0:退出并结算"+"    "+"1:租轿车"+"    "+"2:租客车");
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