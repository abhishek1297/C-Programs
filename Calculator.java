package sample.calc;
import javax.swing.*;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.*;
public class Calculator implements ActionListener
{
		JFrame f;
		static JTextField t;
		JButton zero,one,two,three,four,five,six,seven,eight,nine;
		JButton add,sub,div,mul,ans,dot,clr;
		String str=new String();
		float val=0;
		boolean a=false,b=false,c=false,d=false;
	public Calculator()
	{
		//----------Initialization-------
		f=new JFrame("Calculator");
		t=new JTextField();
		one=new JButton("1");
		two=new JButton("2");
		three=new JButton("3");
		four=new JButton("4");
		five=new JButton("5");
		six=new JButton("6");
		seven=new JButton("7");
		eight=new JButton("8");
		nine=new JButton("9");
		zero=new JButton("0");
		add=new JButton("+");
		sub=new JButton("-");
		mul=new JButton("x");
		div=new JButton("/");
		dot=new JButton(".");
		ans=new JButton("=");
		clr=new JButton("Clear");
		t.setEditable(false);
		t.setFont(new Font("Comic Sans Ms",Font.PLAIN,15));
		t.setBackground(Color.decode("#032035"));
		t.setForeground(Color.decode("#D0D04F"));
		f.getContentPane().setBackground(Color.decode("#0F5C94"));
		f.setVisible(true);
		f.setLayout(null);
		f.setLocation(250,250);
		//------------TextBox--------------
		t.setBounds(600,300,290,100);
		f.add(t);
		//----------Number Buttons---------
		one.setBounds(600,410,50,50);
		one.addActionListener(this);
		f.add(one);
		two.setBounds(680,410,50,50);
		two.addActionListener(this);
		f.add(two);
		three.setBounds(760,410,50,50);
		three.addActionListener(this);
		f.add(three);
		four.setBounds(600,480,50,50);
		four.addActionListener(this);
		f.add(four);
		five.setBounds(680,480,50,50);
		five.addActionListener(this);
		f.add(five);
		six.setBounds(760,480,50,50);
		six.addActionListener(this);
		f.add(six);
		seven.setBounds(600,550,50,50);
		seven.addActionListener(this);
		f.add(seven);
		eight.setBounds(680,550,50,50);
		eight.addActionListener(this);
		f.add(eight);
		nine.setBounds(760,550,50,50);
		nine.addActionListener(this);
		f.add(nine);
		zero.setBounds(680,620,50,50);
		zero.addActionListener(this);
		f.add(zero);
		//-----Arithmetic Buttons--------
		add.setBounds(840,410,50,50);
		add.addActionListener(this);
		f.add(add);
		sub.setBounds(840,480,50,50);
		sub.addActionListener(this);
		f.add(sub);
		mul.setBounds(840,550,50,50);
		mul.addActionListener(this);
		f.add(mul);
		div.setBounds(840,620,50,50);
		div.addActionListener(this);
		f.add(div);
		ans.setBounds(760,620,50,50);
		ans.addActionListener(this);
		f.add(ans);
		dot.setBounds(600,620,50,50);
		dot.addActionListener(this);
		f.add(dot);
		clr.setBounds(600,690,290,50);
		clr.addActionListener(this);
		f.add(clr);
	}
	public static void main(String args[])
	{
		new Calculator();
	}
	@Override
	public void actionPerformed(ActionEvent ac) 
	{
		
		String temp;
		try
		{
		//----------Number Buttons-------------
		if(ac.getSource()==one)
		{
			str=str+"1";
		}
		else
		if(ac.getSource()==two)
		{
			str=str+"2";
		}
		else
		if(ac.getSource()==three)
		{
			str=str+"3";
		}
		else	
		if(ac.getSource()==four)
		{
			str=str+"4";
		}
		else
		if(ac.getSource()==five)
		{
			str=str+"5";
		}
		else
		if(ac.getSource()==six)
		{
			str=str+"6";
		}
		else
		if(ac.getSource()==seven)
		{
			str=str+"7";
		}
		else
		if(ac.getSource()==eight)
		{
			str=str+"8";
		}
		else
		if(ac.getSource()==nine)
		{
			str=str+"9";
		}
		if(ac.getSource()==zero)
		{
			str=str+"0";
		}
		//-------Operator Buttons-----------
		else
		if(ac.getSource()==dot)
		{
			if(!t.getText().equals(""))
				str=str+".";
			else
				str=str+"0.";
		}
		else
		if(ac.getSource()==add)
		{
			if(!t.getText().equals(""))
			{	
				str=str+"+";
				a=true;
			}
			else
				t.setText("Invalid");
			
		}
		else
		if(ac.getSource()==sub)
		{
			if(!t.getText().equals(""))
			{
				str=str+"-";
				b=true;

			}
			else
				t.setText("Invalid");
		}
		else
		if(ac.getSource()==mul)
		{
			str=str+"x";
			c=true;
		}
		else
		if(ac.getSource()==div)
		{
			if(!t.getText().equals(""))
			{
				str=str+"/";
				d=true;
			}
			else
				t.setText("Invalid");
		}
		else
		if(ac.getSource()==ans)
		{
			temp=t.getText();
			System.out.println(temp);
			if(a)
			{
				val=addition(temp);
				a=false;
			}
			if(b)
			{
				val=subtract(temp);
				b=false;
			}
			if(c)
			{
				val=multiply(temp);
				c=false;
			}
			if(d)
			{
				val=divide(temp);
				d=false;
			}
			str=str+"="+new Float(val).toString();
		}
		else
		if(ac.getSource()==clr)
		{
			str=new String();
			val=0f;
		}
		}
		catch(Exception e)
		{
			System.out.println("Problem :"+e.getMessage());
		}
		finally
		{
			//printing every call
			t.setText(str);

		}
		
		
	}
	public static float addition(String str)
	{
		float val=0;
		System.out.println("in add");
		String arr[]=str.split("\\+");
		float n;
		for(String i:arr)
		{
			if(i.equals(""))
				n=0;
			else
				n=Float.parseFloat(i);
			val+=n;
		}
		return val;
		
	}
	public static float multiply(String str)
	{
		float n,val=1;
		System.out.println("in multiply");
		String arr[]=str.split("[^0-9]");
		for(String i:arr)
		{
			n=Float.parseFloat(i);
			val=val*n;
		}
		return val;
	}
	public static float subtract(String str)
	{
		float val=0;
		System.out.println("in sub");
		String arr[]=str.split("\\-");
		
		val=Integer.parseInt(arr[0]);
			for(int i=1;i<arr.length;i++)
			{
				float n=Float.parseFloat(arr[i]);
				val=val-n;
			}
			return val;
	}
	public static float divide(String str)
	{
		float n1,n2,val=1;
		System.out.println("in div");
		String arr[]=str.split("/");
		
		if(arr.length==2)
		{
			n1=Float.parseFloat(arr[0]);
			n2=Float.parseFloat(arr[1]);
			val=n1/n2;
		}
		else
			t.setText("Invalid");
		return val;
	}
	
}


