using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 用户界面
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void add()
        {
            if (comboBox1.Text == "学生")
            {
                string sql = "select*from student where Name='" + textBox1.Text + "'and PassWord='" + textBox2.Text + "'";
                Dao dao = new Dao();
                IDataReader dr = dao.read(sql);
                dr.Read();
                string sId = dr["Id"].ToString();
                Form3 form3 = new Form3(sId);
                form3.Show();
                this.Hide();
            }
            if (comboBox1.Text == "老师")
            {
                Form2 form2 = new Form2();
                form2.Show();
                this.Hide();
            }
            if (comboBox1.Text == "管理员")
            {
                Form4 form4 = new Form4();
                form4.Show();
                this.Hide();
            }
        }
        //登录事件
        private void button1_Click(object sender, EventArgs e)
        {
            if (login())
            {
                add();
                textBox1.Visible = false;
                textBox2.Visible = false;
                comboBox1.Visible = false;
                button1.Visible = false;
                button2.Visible = false;
                label1.Visible = false;
                label2.Visible = false;
                label3.Visible = false;
                
            }
        }
        private bool login()
        {
            if(textBox1.Text ==""||textBox2.Text ==""||comboBox1.Text  =="")
            {
                MessageBox.Show("输入不完整，请重新输入","提示",MessageBoxButtons.OK,MessageBoxIcon.Warning);
                return false;
            }
            if(comboBox1 .Text == "学生")
            {
                string sql = "select*from student where Name='"+textBox1 .Text +"'and PassWord='"+textBox2.Text +"'";
                Dao dao = new Dao();
                IDataReader dr=dao.read(sql);
                if(dr.Read())
                {
                    return true;
                }
                else
                {
                    MessageBox.Show("用户名或密码错误！", "提示");
                    return false;
                }
            }
            if(comboBox1 .Text =="老师")
            {
               string sql = "select*from teacher where Name='" + textBox1.Text + "'and PassWord='" + textBox2.Text + "'";
                Dao dao = new Dao();
                IDataReader dr = dao.read(sql);
                if (dr.Read())
                {
                    return true;
                }
                else
                {
                    MessageBox.Show("用户名或密码错误！", "提示");
                    return false;
                }
            }
            if(comboBox1 .Text=="管理员")
            {
                if (textBox1.Text == "admin" && textBox2.Text == "admin")
                {
                    return true;
                }
                MessageBox.Show("用户名或密码错误！", "提示");
                return false;
            }
            return false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = null;
            textBox2.Text = null;
            comboBox1.Text = null;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
