
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
	String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + request.getContextPath();
%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<script language="JavaScript" src="../../script/jquery.js"></script>
<script language="JavaScript" src="../../script/menu.js"></script>
<link type="text/css" rel="stylesheet" href="../../style/blue/menu.css" />
<title>Insert title here</title>
</head>
<body style="margin: 0">
<div id="Menu">
    <ul id="MenuUl">
    
		<c:if test="${sessionInfo.loginUserType == '1'}">		
    	<li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../../style/images/MenuIcon/FUNC23700.gif" class="Icon" /> 内容管理</div>
            <ul style="display: none;" class="MenuLevel2">
                
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../releaseInfo.jsp">信息发布</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../upload.jsp">文件上传</a></div>
                </li>
                 <!-- 
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="<%= basePath %>/system/pages/getDatagridAction.action">管理记录</a></div>
                </li> 
                -->               
            </ul>
        </li>
        <li class="level1">
         <div onClick="menuClick(this);" class="level1Style"><img src="../../style/images/MenuIcon/FUNC249000.gif" class="Icon" /> 模块管理</div>
            <ul style="display: none;" class="MenuLevel2">
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=publicPost">通知公告</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=news">科技资讯</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=industryInfo">行业信息</a></div>
                </li>
                
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getPatDataAction.action">专利池</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getAchDataAction.action">成果库</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getNeedDataAction.action">技术需求</a></div>
                </li> 
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=countryrules">国家政策法规</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=provincerules">辽宁省政策法规</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=cityrules">沈阳市政策法规</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=schoolrules">我校政策法规</a></div>
                </li>
                 <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=ourSchool">我校科研基地</a></div>
                </li>
                 <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=domestic">国内科研基地</a></div>
                </li>
                 <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getFBDataAction.action?type=abroad">国外科研基地</a></div>
                </li>              
               <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="getMBDateAction.action">留言板</a></div>
                </li>  
            </ul>
        </li>
        <li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../../style/images/MenuIcon/FUNC20082.gif" class="Icon" /> 系统管理</div>
            <ul style="display: none;" class="MenuLevel2">
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="<%= basePath %>/system/pages/userManageAction.action"> 用户管理</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html"> 管理授权码</a></div>
                </li>
            </ul>
        </li>
        </c:if>
        <!-- 科研教师 -->
        <c:if test="${sessionInfo.loginUserType == '2'}">	
        <li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../../style/images/MenuIcon/FUNC20082.gif" class="Icon" /> 科技成果</div>
            <ul style="display: none;" class="MenuLevel2">
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html"> 科技成果申请</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html"> 我的申请记录</a></div>
                </li>
            </ul>
        </li>
        </c:if>
         <!-- 公司企业 -->
        <c:if test="${sessionInfo.loginUserType == '3'}">	
        <li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../../style/images/MenuIcon/FUNC20082.gif" class="Icon" />技术需求</div>
            <ul style="display: none;" class="MenuLevel2">
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">技术需求申请</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">我的申请记录</a></div>
                </li>
            </ul>
        </li>
        </c:if>
        
        <!-- 公共部分 -->
        <li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../../style/images/MenuIcon/FUNC20076.gif" class="Icon" /> 实用工具</div>
            <ul style="display: none;" class="MenuLevel2">
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../importExcel.jsp">导入Excel表格</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="_blank" href="http://www.neu.edu.cn">学校官网</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="_blank" href="http://www.12306.cn/">火车时刻</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="_blank" href="http://www.airchina.com.cn/">飞机航班</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="_blank" href="http://www.ip138.com/post/">邮编/区号</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="_blank" href="http://www.timedate.cn/">国际时间</a></div>
                </li>
            </ul>
        </li>
        
        <li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../../style/images/MenuIcon/FUNC20077.gif" class="Icon" /> 个人设置</div>
            <ul style="display: none;" class="MenuLevel2">
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">个人信息</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">密码修改</a></div>
                </li>                
            </ul>
        </li>
        
        
        
        <!-- 
        <li class="level1">
            <div onClick="menuClick(this)" class="level1Style"><img src="../../style/images/MenuIcon/FUNC20001.gif" class="Icon" /> 成果专利库</div>
            <ul style="display: none;" class="MenuLevel2">
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../techNews/addTechNews.jsp">典型案例</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html"> 重点推荐</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">计算机科学与技术</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">控制科学与工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">材料科学与工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">冶金工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">机械工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">矿业工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">哲学</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">应用经济学</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">管理科学与工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">生物医学工程</a></div>
                </li>
                
            </ul>
        </li>
        <li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../../style/images/MenuIcon/FUNC20057.gif" class="Icon" /> 企业需求审批</div>
            <ul style="display: none;" class="MenuLevel2">
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">计算机科学与技术</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">控制科学与工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">材料科学与工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">冶金工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">机械工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">矿业工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">哲学</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">应用经济学</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">管理科学与工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">生物医学工程</a></div>
                </li>
                
            </ul>
        </li>
        <li class="level1">
            <div onClick="menuClick(this);" class="level1Style"><img src="../../style/images/MenuIcon/FUNC20064.gif" class="Icon" /> 科技专家库</div>
            <ul style="display: none;" class="MenuLevel2">
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">计算机科学与技术</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">控制科学与工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">材料科学与工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">冶金工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">机械工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">矿业工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">哲学</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">应用经济学</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">管理科学与工程</a></div>
                </li>
                <li class="level2">
                    <div class="level2Style"><img src="../../style/images/MenuIcon/menu_arrow_single.gif" /> <a target="right" href="../test.html">生物医学工程</a></div>
                </li>       
            </ul>
        </li>
        <li class="level1">
            <div class="level1Style"><img src="../../style/images/MenuIcon/FUNC20056.gif" class="Icon" /> <a target="right" href="../test.html">动态资讯</a></div>
        </li>
        -->
        
    </ul>
</div>
</body>
</html>