﻿using System;
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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            toolStripStatusLabel3.Text = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
            timer1.Start();
            Table();
        }

        private void 添加学生ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form21 f= new Form21();
            f.ShowDialog();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            toolStripStatusLabel3.Text = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();//结束整个程序
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
        //让表显示数据
        private void Table()
        {
            dataGridView1.Rows.Clear();
            string sql = "select*from student";
            Dao dao = new Dao();
            IDataReader dr = dao.read(sql);
            while(dr.Read())
            {
                string a, b, c, d, e;//表示读取到的数据类型
                a = dr["Id"].ToString();
                b = dr["Name"].ToString();
                c = dr["Class"].ToString();
                d = dr["Birthday"].ToString();
                e = dr["Address"].ToString();
                string[] str = { a, b, c, d, e };
                dataGridView1.Rows.Add(str); 
            }
            dr.Close();//关闭连接
        }

        private void 修改学生信息ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                string[] str = { dataGridView1.SelectedCells[0].Value.ToString(), dataGridView1.SelectedCells[1].Value.ToString(),
                dataGridView1.SelectedCells[2].Value.ToString(), dataGridView1.SelectedCells[3].Value.ToString(), dataGridView1.SelectedCells[4].Value.ToString() };
                Form21 f = new Form21(str);
                f.ShowDialog();
            }
            catch
            {
                MessageBox.Show("请先选中一行");
            }
        }

        private void 删除学生信息ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult r = MessageBox.Show("确定要删除吗？", "提示", MessageBoxButtons.OKCancel);
            if (r == DialogResult.OK)
            {
                string id, name;
                id = dataGridView1.SelectedCells[0].Value.ToString();
                name = dataGridView1.SelectedCells[1].Value.ToString();
                string sql = "delete from student where Id='" + id + "'and Name='" + name + "'";
                MessageBox.Show(sql);
                Dao dao = new Dao();
                dao.Execute(sql);
                Table();
            }
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            Table();
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();//结束整个程序
        }
    }
}
