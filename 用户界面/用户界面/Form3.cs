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
    public partial class Form3 : Form
    {
        string SID;
        public Form3(string sID)
        {
            SID = sID;
            InitializeComponent();
            toolStripStatusLabel3.Text = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
            timer1.Start();
            Table();
        }
        private void Table()
        {
            dataGridView1.Rows.Clear();
            string sql = "select*from Course";
            Dao dao = new Dao();
            IDataReader dr = dao.read(sql);
            while (dr.Read())
            {
                string a, b, c, d;//表示读取到的数据类型
                a = dr["Id"].ToString();
                b = dr["Name"].ToString();
                c = dr["Teacher"].ToString();
                d = dr["Credit"].ToString();
                string[] str = { a, b, c, d };
                dataGridView1.Rows.Add(str);
            }
            dr.Close();//关闭连接
        }


        private void 选课ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string cID = dataGridView1.SelectedCells[0].Value.ToString();//获取选中的课程号
            string sql1 = "select * from CourseRecord where sId='" + SID + "'and'" + cID + "'";//查询是否选过课
            Dao dao = new Dao();
            IDataReader dc = dao.read(sql1);
            string sql = "Insert into CourseRecord values('" + SID + "','" + cID + "')";
            int i = dao.Execute(sql);
            if (!dc.Read())
            {
                if (i > 0)
                {
                    MessageBox.Show("选课成功");
                }
            }
            else
            {
                MessageBox.Show("不允许重复选课");
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            toolStripStatusLabel3.Text = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        private void Form3_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();//结束整个程序
        }

        private void 我的课程ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form31 f = new Form31(SID);
            f.Show();
        }
    }
}
