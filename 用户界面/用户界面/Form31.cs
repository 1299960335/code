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
    public partial class Form31 : Form
    {
        string SID;
        public Form31(string sID)
        {
            InitializeComponent();
            SID = sID;
            Table();
        }
        private void Table()
        {
            dataGridView1.Rows.Clear();
            string sql = "select*from CourseRecord where sId='"+SID+"'";
            Dao dao = new Dao();
            IDataReader dr = dao.read(sql);
            while (dr.Read())
            {
                string cID = dr["cId"].ToString();
                string sql2 = "select * from Course where Id='" + cID + "'";
                IDataReader dr2 = dao.read(sql2);
                dr2.Read();
                string a, b, c, d;//表示读取到的数据类型
                a = dr2["Id"].ToString();
                b = dr2["Name"].ToString();
                c = dr2["Teacher"].ToString();
                d = dr2["Credit"].ToString();
                string[] str = { a, b, c, d };
                dataGridView1.Rows.Add(str);
                dr2.Close();
            }
            dr.Close();//关闭连接
        }

        private void Form31_Load(object sender, EventArgs e)
        {

        }

        private void 取消这门课程ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string cID = dataGridView1.SelectedCells[0].Value.ToString();
            string sql = "delete CourseRecord where sId='" + SID + "'and cId='" + cID + "'";
            Dao dao = new Dao();
            dao.Execute(sql);
            Table();
        }
    }
}
