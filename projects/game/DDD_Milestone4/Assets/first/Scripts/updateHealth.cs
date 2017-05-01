using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;

public class updateHealth : MonoBehaviour {


	Text text;
	// Use this for initialization
	void Start () {
		text = GetComponentInParent<Text> ();
	
	}

	// Update is called once per frame
	void Update () {
		
		text.text = "Health " + PlayerPrefs.GetInt("health") + "/10"; 
	
	}

	void retryScreen () 
	{
		if (PlayerPrefs.GetInt ("health") == 0 ) 
		{
			//load retry scene
		}
	}
}
