<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="UTf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTf-8">
<script language="JavaScript" src="../script/jquery.js"></script>
<script language="JavaScript" src="../script/menu.js"></script>
<link type="text/css" rel="stylesheet" href="../style/css/menu.css" />
<title>Insert title here</title>
</head>
<body>
//zahuishi 纳尼？图片呢？？？？？？？？
	<div id="Menu">
		<ul id="MenuUl">
		<li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../style/images/MenuIcon/folder.gif" class="Icon" /> 人员管理</div>
            <ul style="display: none;" class="MenuLevel2">
                
                <li class="level2">
                    <div class="level2Style"><img src="../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="staffReview.jsp">注册审核</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../upload.jsp">人员删除</a></div>
                </li>
                              
            </ul>
        </li>
        <li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../style/images/MenuIcon/folder.gif" class="Icon" /> 部门管理</div>
            <ul style="display: none;" class="MenuLevel2">
                
                <li class="level2">
                    <div class="level2Style"><img src="../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="releaseInfo.jsp">信息发布</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../upload.jsp">文件上传</a></div>
                </li>
                              
            </ul>
        </li>
        <li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../style/images/MenuIcon/folder.gif" class="Icon" /> 设备管理</div>
            <ul style="display: none;" class="MenuLevel2">
                
                <li class="level2">
                    <div class="level2Style"><img src="../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="releaseInfo.jsp">信息发布</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../upload.jsp">文件上传</a></div>
                </li>
                              
            </ul>
        </li>

		</ul>
	</div>
</body>
</html>