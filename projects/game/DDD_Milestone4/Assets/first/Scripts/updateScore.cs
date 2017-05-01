using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class updateScore : MonoBehaviour {

	Text text;
	// Use this for initialization
	void Start () {
		text = GetComponentInParent<Text> ();

	}

	void Awake()
	{
		DontDestroyOnLoad (this);
	}

	// Update is called once per frame
	void Update () {
		if (PlayerPrefs.GetInt ("kills") == 0) {
			PlayerPrefs.SetInt ("score", 0);
		} else {
			PlayerPrefs.SetInt ("score", (PlayerPrefs.GetInt ("level") * (PlayerPrefs.GetInt ("kills"))) * 100);
		}

		text.text = "Score " + PlayerPrefs.GetInt("score"); 


	}

}