<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
	String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + request.getContextPath();
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<meta charset="utf-8" />
	<title>添加设备</title>
	<link rel="stylesheet" href="../css/register.css" />
	<script src="<%=basePath %>/js/jquery-1.8.0.min.js"></script>
	<script src="../script/register.js"></script>
	<script src="../script/jquery.complexify.js"></script>
	<script language="javascript" type="text/javascript">
	function change(Names){
			for (var i=0;i<4;i++){
				var tempname="mune_x"+i;
				var NewsHot="x"+i;
				
				if (Names==tempname){
					document.getElementById("x0").style.display='block';
					Nnews=document.getElementById(NewsHot);
					Nnews.style.display='';
		 		}else{
					Nnews=document.getElementById(NewsHot);
					Nnews.style.display='none'; 
				}
			}
		}
		
</script>
      
</head>
    
<body>

        <div id="main">
        	
        	<h1>添加设备</h1>
        	<div style="height:15px"><div style="height:5px" id= "checkname"></div>
        	</div>
        	<form id="register" class="" method="post" action="registAction.action">
        		<!-- 管理员信息，同时是其他用户的基本信息 -->
        		<div id ="x0" style='display:block;overflow:hidden;text-align:center;'>
        		<div class="row userName">
        			<input type="text" id="userName" name="userName" placeholder="设备唯一标识" />
        		</div>
        		<div class="row pass">
        			<input type="password" id="password1" name="password" placeholder="设备名字" />
        		</div>
        		
        		<div class="row realName">
        			<input type="text" id="realName" name="realName" placeholder="采集信息格式id" />
        		</div>
        		
        		<div class="row birthday">
        			<input type="text" id="birthday" name="birthday" placeholder="设备采集到数据的单位" />
        		</div>
        		<div class="row email">
	    			<input type="text" id="email" name="email" placeholder="制造商" />
        		</div>
        		<div class="row telphone">
        			<input type="text" id="telphone" name="telphone" placeholder="联系方式" />
        		</div>
        		<div class="row telphone">
        			<input type="text" id="telphone" name="telphone" placeholder="安装时间" />
        		</div>       		
        		</div>
        		
        		<!--  <div class="usertype">		
        		<span>用户类型：</span>
				<select name="userType" id="userType" onChange="javascript:change('mune_x'+this.value)">
					<option value="0">--请选择--</option>
					<option value="1">   管理员     </option>
					<option value="2">   科研教师  </option>
					<option value="3">   公司企业      </option>
				</select><br>
        		</div>	-->
        		
        		<div id="x1" style='display:none;overflow:hidden;text-align:center;'>
				<br><div class="auth">
        			<input type="text" id="auth" name="auth" placeholder="授权码" />
        		</div>
        		<div style="height:15px"><div style="height:5px" id= "checkauth"></div></div>
        		</div>
        		
        		<div id="x2" style='display:none;overflow:hidden;text-align:center;'>
        		<br><h2>职务信息</h2>
				<div class="research salaryNo">
        			<input type="text" id="salaryNo" name="salaryNo" placeholder="工资号" />
        		</div>
        		<div class="research department">
        			<input type="text" id="department" name="department" placeholder="所在单位" />
        		</div>
        		<div class="research techPost">
        			<input type="text" id="techPost" name="techPost" placeholder="职称" />
        		</div>
        		<div class="research duty">
        			<input type="text" id="duty" name="duty" placeholder="职务" />
        		</div>
        		<div class="research researchField">
        			<input type="text" id="researchField" name="researchField" placeholder="研究领域" />
        		</div>
				</div>
				
        		<div id="x3" style='display:none;overflow:hidden;text-align:center;'>
        		<br><h2>企业信息</h2>
				<div class="etprs enterpriseName">
        			<input type="text" id="enterpriseName" name="enterpriseName" placeholder="企业名称" />
        		</div>
        		<div class="etprs orgCode">
        			<input type="text" id="orgCode" name="orgCode" placeholder="组织机构代码" />
        		</div>
        		<div class="etprs taxCode">
        			<input type="text" id="taxCode" name="taxCode" placeholder="税务代码" />
        		</div>
        		<div class="etprs legPerCode">
        			<input type="text" id="legPerCode" name="legPerCode" placeholder="法人代码" />
        		</div>
        		<div class="etprs legPerName">
        			<input type="text" id="legPerName" name="legPerName" placeholder="法人代表姓名" />
        		</div>
				</div>
        			
        		<input type="submit" value="添加" />
        		
        	</form>
        </div>
        
        <footer>
	        
            <a class="al3xis"> Northeastern University </a>
        </footer>
        
		     
    </body>
</html>