
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

/*
Source: 
https://stackoverflow.com/questions/30056471/how-to-make-the-script-wait-sleep-in-a-simple-way-in-unity
https://www.youtube.com/watch?v=5TOHaygv1IE&t=199s
https://www.minitool.com/news/object-reference-not-set-to-an-instance-of-an-object.html
https://docs.unity3d.com/2018.2/Documentation/ScriptReference/UI.Text-text.html
*/

public class levelLoader : MonoBehaviour
{
    public int iLevelToLoad;
    public string sLevelToLoad;
    public Text myText;
    public string newText;
    public bool useIntegerToLoadLevel = false;

    void Start()
    {
        //transform.position = new Vector3(-5, 4, 0);
        GameObject TextGameObject = GameObject.Find("Text");
        myText = TextGameObject.GetComponent<UnityEngine.UI.Text>();
        DontDestroyOnLoad(gameObject);
    }

    void Update()
    {

    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        GameObject collisionGameObject = collision.gameObject;

        if (collisionGameObject.name == "Chest")
        {
            StartCoroutine(SomeCoroutine());
        }
        if(collisionGameObject.name == "Coin")
        {
             Destroy(collision.gameObject);
             myText.text = "Whenever you hit a coin you get a point!";
        }
    }

    private IEnumerator SomeCoroutine()
    {
        myText.text = "On to Level 2";
        yield return new WaitForSeconds (1);
        LoadScene(); 
        transform.position = new Vector3(-6, 2, 0);
   
    }

    void LoadScene()
    {
        if(useIntegerToLoadLevel)
        {
            SceneManager.LoadScene(iLevelToLoad);
        }
        else 
        {
            SceneManager.LoadScene(sLevelToLoad);
        }
    }
}
