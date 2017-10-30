using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Life_2._0
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}
	}

	public abstract class Life
	{
		public uint MaxHp { get { return MaxHp; } }

		public uint Health { get { return Health; } }

		public HashSet<Fact> Expierence;

		public abstract void Use(Object a);// использовать какое то знание на каком то объекте

		
	}
	
	public class Fact
	{
		public Object It { get { return It; } }
	}

	public class Object
	{

	}
}
