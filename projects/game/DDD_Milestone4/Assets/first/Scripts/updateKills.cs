using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class updateKills : MonoBehaviour {

	Text text;
	// Use this for initialization
	void Start () {
		text = GetComponentInParent<Text> ();
		DontDestroyOnLoad (this);
	}

	void Awake()
	{
		DontDestroyOnLoad (this);
	}

	// Update is called once per frame
	void Update () {

		text.text = "Kills " + PlayerPrefs.GetInt("kills"); 


	}

}
