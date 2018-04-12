/**
 * 
 */
package business.icpscloud.facility.action;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.apache.struts2.ServletActionContext;

import com.opensymphony.xwork2.Action;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import com.opensymphony.xwork2.ModelDriven;

//import business.icpscloud.facility.entity.FacilityDataEntity;
import business.icpscloud.facility.entity.FacilityEntity;
import business.icpscloud.facility.service.FacilityService;


/**
 * @author LiPeiXu
 * @ModifyDate 2017年6月20日
 */
public class FacilityAction extends ActionSupport implements ModelDriven<FacilityEntity> {
	private static final long serialVersionUID = 1L;
	private int DataID;
	private String Data1;
	private String Data2;
	private String data3;
	private String Data4;
	private String Data5;
	private String data6;
    
	HttpServletRequest request = ServletActionContext.getRequest();
	 HttpServletResponse response = ServletActionContext.getResponse();
	 private FacilityEntity facilityEntity = new FacilityEntity();	
	 private List<FacilityEntity> facL = new ArrayList<FacilityEntity>();
	 List<FacilityEntity> list = new ArrayList<FacilityEntity>();
	 private  ArrayList<String>  strArrayTime = new ArrayList<String> (); 
	 private  ArrayList<String>  strArrayData1 = new ArrayList<String> (); 
	 private  ArrayList<String>  strArrayData2 = new ArrayList<String> (); 
	 private ArrayList<String>  strArrayData3= new ArrayList<String> (); 
	 private  ArrayList<String>  strArrayData4 = new ArrayList<String> (); 
	 private  ArrayList<String>  strArrayData5 = new ArrayList<String> (); 
	 private ArrayList<String>  strArrayData6= new ArrayList<String> (); 
	 public ArrayList<String> getStrArrayData4() {
		return strArrayData4;
	}
	public void setStrArrayData4(ArrayList<String> strArrayData4) {
		this.strArrayData4 = strArrayData4;
	}
	public ArrayList<String> getStrArrayData5() {
		return strArrayData5;
	}
	public void setStrArrayData5(ArrayList<String> strArrayData5) {
		this.strArrayData5 = strArrayData5;
	}
	public ArrayList<String> getStrArrayData6() {
		return strArrayData6;
	}
	public void setStrArrayData6(ArrayList<String> strArrayData6) {
		this.strArrayData6 = strArrayData6;
	}
	private FacilityService facilityService ;
	 @Override
		public FacilityEntity getModel() {			
			return facilityEntity;
		}
      public String finddetail(){  	    	
    	 System.out.println("1");
    	  ActionContext ac=ActionContext.getContext();		
    	 // String Data1 = "21";
    	  facilityEntity = facilityService.findById();
    	  facL = facilityService.findListByLimit(0,5);
    	  System.out.println(facL);
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayTime.add("'"+facL.get(i).getTime().substring(10,facL.get(i).getTime().length())+"'");
    		}    	 
    	  ac.put("time",strArrayTime);
    	  
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData1.add(facL.get(i).getData1());
    		}
    	  
    	  /*
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData2.add(facL.get(i).getData2());
    		}
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData3.add(facL.get(i).getData3());
    		}   
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData4.add(facL.get(i).getData4());
    		}   
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData5.add(facL.get(i).getData5());
    		}   
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData6.add(facL.get(i).getData6());
    		}  
    		*/ 
    	  ac.put("data1",strArrayData1);
    	  //ac.put("data2",strArrayData1);
    	 // ac.put("data3",strArrayData1);
    	  //ac.put("data4",strArrayData1);
    	  //ac.put("data5",strArrayData1);
    	  //ac.put("data6",strArrayData1);
    	  ac.put("fal", facL);
    	  return "success";
          }   
      public String finddetail2(){  	  	  
    	  ActionContext ac=ActionContext.getContext();	  
    	 // String Data1 = "21";
    	  facilityEntity = facilityService.findById();
    	  facL = facilityService.findListByLimit(0,5);
    	  System.out.println(facL);   	  
    	  
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData2.add(facL.get(i).getData2());
    		}
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayTime.add("'"+facL.get(i).getTime().substring(10,facL.get(i).getTime().length())+"'");
    		}    	 
    	  ac.put("time",strArrayTime);
    	  ac.put("data2",strArrayData2);
    	  ac.put("fal", facL);
    	  return "success";
          }   
      public String finddetail3(){  	
    	  ActionContext ac=ActionContext.getContext();	  
    	 // String Data1 = "21";
    	  facilityEntity = facilityService.findById();
    	  facL = facilityService.findListByLimit(0,5);
    	  System.out.println(facL);   	  
    	  
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData3.add(facL.get(i).getData3());
    		}    	  
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayTime.add("'"+facL.get(i).getTime().substring(10,facL.get(i).getTime().length())+"'");
    		}    	 
    	  ac.put("time",strArrayTime);
    	  ac.put("data3",strArrayData3);
    	  ac.put("fal", facL);
    	  return "success";
          }   
      public String finddetail4(){  	
    	  ActionContext ac=ActionContext.getContext();	  
    	 // String Data1 = "21";
    	  facilityEntity = facilityService.findById();
    	  facL = facilityService.findListByLimit(0,5);
    	  System.out.println(facL);   	  
    	  
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData4.add(facL.get(i).getData4());
    		}  
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayTime.add("'"+facL.get(i).getTime().substring(10,facL.get(i).getTime().length())+"'");
    		}    	 
    	  ac.put("time",strArrayTime);
    	  ac.put("data4",strArrayData4);
    	  ac.put("fal", facL);
    	  return "success";
          }   
      public String finddetail5(){  	
    	  ActionContext ac=ActionContext.getContext();	  
    	 // String Data1 = "21";
    	  facilityEntity = facilityService.findById();
    	  facL = facilityService.findListByLimit(0,5);
    	  System.out.println(facL);   	  
    	  
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData5.add(facL.get(i).getData5());
    		}    	 
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayTime.add("'"+facL.get(i).getTime().substring(10,facL.get(i).getTime().length())+"'");
    		}    	 
    	  ac.put("time",strArrayTime);
    	  ac.put("data5",strArrayData5);
    	  ac.put("fal", facL);
    	  return "success";
          }   
      public String finddetail6(){  	
    	  ActionContext ac=ActionContext.getContext();	  
    	 // String Data1 = "21";
    	  facilityEntity = facilityService.findById();
    	  facL = facilityService.findListByLimit(0,5);
    	  System.out.println(facL);   	  
    	  
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayData6.add(facL.get(i).getData6());
    		} 
    	  for( int i = 0 ; i < facL.size() ; i++) {//内部不锁定，效率最高，但在多线程要考虑并发操作的问题。
    		  strArrayTime.add("'"+facL.get(i).getTime().substring(10,facL.get(i).getTime().length())+"'");
    		}    	 
    	  ac.put("time",strArrayTime);
    	  ac.put("data6",strArrayData6);
    	  ac.put("fal", facL);
    	  return "success";
          }   
      /*
      public String getdata(){
    	  System.out.println("实验");
    	  list.add(new FacilityEntity(1,"2","3","4","5","6","7","8"));
    	  list.add(new FacilityEntity(1,"2","3","4","5","6","7","8"));
    	  list.add(new FacilityEntity(1,"2","3","4","5","6","7","8"));
    	  return "success";
  //System.out.println(json);
          
          //将json数据返回给客户端            
      }
      */
            
      public HttpServletRequest getRequest() {
		return request;
	}
	public void setRequest(HttpServletRequest request) {
		this.request = request;
	}
	public HttpServletResponse getResponse() {
		return response;
	}
	public void setResponse(HttpServletResponse response) {
		this.response = response;
	}
	public FacilityEntity getFacilityEntity() {
  		return facilityEntity;
  	}
  	public void setFacilityEntity(FacilityEntity facilityEntity) {
  		this.facilityEntity = facilityEntity;
  	}
  	public FacilityService getFacilityService() {
  		return facilityService;
  	}
  	public void setFacilityService(FacilityService facilityService) {
  		this.facilityService = facilityService;
  	}
	public int getDataID() {
		return DataID;
	}
	public void setDataID(int dataID) {
		DataID = dataID;
	}
	
	public String getData1() {
		return Data1;
	}
	public void setData1(String data1) {
		Data1 = data1;
	}
	public String getData2() {
		return Data2;
	}
	public void setData2(String data2) {
		Data2 = data2;
	}
	public String getData3() {
		return data3;
	}
	public void setData3(String data3) {
		this.data3 = data3;
	}
	
	public String getData4() {
		return Data4;
	}
	public void setData4(String data4) {
		Data4 = data4;
	}
	public String getData5() {
		return Data5;
	}
	public void setData5(String data5) {
		Data5 = data5;
	}
	public String getData6() {
		return data6;
	}
	public void setData6(String data6) {
		this.data6 = data6;
	}
	public static long getSerialversionuid() {
		return serialVersionUID;
	}
	public List<FacilityEntity> getFacL() {
		return facL;
	}
	public void setFacL(List<FacilityEntity> facL) {
		this.facL = facL;
	}
	public ArrayList<String> getStrArrayTime() {
		return strArrayTime;
	}
	public void setStrArrayTime(ArrayList<String> strArrayTime) {
		this.strArrayTime = strArrayTime;
	}
	public ArrayList<String> getStrArrayData1() {
		return strArrayData1;
	}
	public void setStrArrayData1(ArrayList<String> strArrayData1) {
		this.strArrayData1 = strArrayData1;
	}
	public ArrayList<String> getStrArrayData2() {
		return strArrayData2;
	}
	public void setStrArrayData2(ArrayList<String> strArrayData2) {
		this.strArrayData2 = strArrayData2;
	}
	public ArrayList<String> getStrArrayData3() {
		return strArrayData3;
	}
	public void setStrArrayData3(ArrayList<String> strArrayData3) {
		this.strArrayData3 = strArrayData3;
	}
	
}
