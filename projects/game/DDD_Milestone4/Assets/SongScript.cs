using UnityEngine;
using System.Collections;

public class SongScript : MonoBehaviour {
	public AudioSource a;
	public AudioClip first;
	public AudioClip second;
	public AudioClip third;
	public AudioClip fourth;


	// Use this for initialization
	void Start () {
		if (PlayerPrefs.GetInt ("level") <= 3)
		{
			a.clip = first;
		}
		if (PlayerPrefs.GetInt ("level") <= 6 && PlayerPrefs.GetInt ("level") > 3)
		{
			a.clip = second;
		}
		if (PlayerPrefs.GetInt ("level") <= 9 && PlayerPrefs.GetInt ("level") > 6)
		{
			a.clip = third;
		}
		if (PlayerPrefs.GetInt ("level") > 9)
		{
			a.clip = fourth;
		}
		a.Play ();
	}
	
	// Update is called once per frame
	void Update () {

	}
}
